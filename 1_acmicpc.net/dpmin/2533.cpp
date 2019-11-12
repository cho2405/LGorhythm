#include <iostream>
#include <list>

using namespace std;

typedef struct {
    bool visit;
    list<int> friends;
} Node;

int N;
Node node[1000001];
int even_odd_Sum[2]; //0: Even, 1: Odd

void travel(int n, int level) {
    node[n].visit = true;
    even_odd_Sum[level%2]++;

    for (auto it = node[n].friends.begin(); it != node[n].friends.end(); it++)
        if (!node[*it].visit) travel(*it, level+1);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;

        node[u].visit = false;
        node[v].visit = false;
        node[u].friends.push_back(v);
        node[v].friends.push_back(u);
    }

    travel(1, 1);

    cout << min(even_odd_Sum[0], even_odd_Sum[1]) << endl;

    return 0;
}
