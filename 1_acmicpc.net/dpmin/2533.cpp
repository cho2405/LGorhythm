#include <iostream>
#include <list>

using namespace std;

typedef struct {
    bool visit, pick;
    list<int> friends;
} Node;

int N;
Node node[1000001];

int travel(int n) {
    node[n].visit = true;

    int ret = 0;
    for (auto it = node[n].friends.begin(); it != node[n].friends.end(); it++)
        if (!node[*it].visit) {
            ret += travel(*it);
            if (!node[*it].pick) node[n].pick = true;
        }

    return ret + (node[n].pick ? 1 : 0);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;

        node[u].visit = false; node[v].visit = false;
        node[u].pick  = false; node[v].pick  = false;
        node[u].friends.push_back(v);
        node[v].friends.push_back(u);
    }

    cout << travel(1) << endl;

    return 0;
}
