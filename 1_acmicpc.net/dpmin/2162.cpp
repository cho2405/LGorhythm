#include <iostream>

using namespace std;

typedef struct {
    int x, y;
} Point;

bool operator < (Point &p1, Point &p2) {
    if (p1.x < p2.x) return true;
    else if (p1.x == p2.x && p1.y < p2.y) return true;

    return false;
}

bool operator <= (Point &p1, Point &p2) {
    if (p1.x == p2.x && p1.y == p2.y) return true;

    return p1 < p2;
}

void swap(Point &a, Point &b) {
    Point tmp = a;
    a = b;
    b = tmp;
}

typedef struct {
    int group;
    Point p1, p2;
} Line;

int ccw(Point &p1, Point &p2, Point &p3) {
    // return positive when p1->p2->p3 is ccw (otherwise, return negative if it is cw)
    int ret = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x;

    if (ret) return ret > 0 ? 1 : -1;
    return 0;
}

bool isIntersect(Line &l1, Line &l2) {
    int L1L2 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int L2L1 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);

    if (L1L2 == 0 && L2L1 == 0) {
        if (l1.p2 < l1.p1) swap(l1.p2, l1.p1);
        if (l2.p2 < l2.p1) swap(l2.p2, l2.p1);

        return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
    }

    return L1L2 <= 0 && L2L1 <= 0;
}

int N;
Line L[3000];
bool groupMap[3000][3000];

int dfs(int n, int g) {
    L[n].group = g;

    int size = 1;
    for (int i = 0; i < N; i++)
        if (L[i].group == 0 && groupMap[n][i]) size += dfs(i, g);

    return size;
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        L[i].group = 0; // initialize: Zero means the line is not included in any group
        for (int j = 0; j < N; j++) groupMap[i][j] = false;

        cin >> L[i].p1.x >> L[i].p1.y >> L[i].p2.x >> L[i].p2.y;
    }

    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++)
            if (isIntersect(L[i], L[j])) groupMap[i][j] = groupMap[j][i] = true;

    int groupCnt = 0;
    int largestGroupSize = 0;
    for (int i = 0; i < N; i++)
        if (L[i].group == 0) largestGroupSize = max(largestGroupSize, dfs(i, ++groupCnt));

    cout << groupCnt << endl << largestGroupSize << endl;

    return 0;
}
