#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
int mem[100];
int cost[100];

unordered_map<int, int> cache[100];
int dp(int n, int m) {
    if (n < 0) return 0;
    else {
        auto it = cache[n].find(m);
        if (it == cache[n].end())
            return cache[n][m] = max(dp(n-1, m), m >= mem[n] ? dp(n-1, m-mem[n])+cost[n] : 0);
        else
            return it->second;
    }

    return 0;
}

int main(void) {
    cin >> N >> M;

    int totalMem = 0;
    for (int i = 0; i < N; i++) {
        cin >> mem[i];
        totalMem += mem[i];
    }

    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        totalCost += cost[i];
    }

    cout << totalCost-dp(N-1, totalMem-M) << endl;

    return 0;
}
