#include <iostream>

using namespace std;

int N, M;
int mem[100];
int cost[100];

int cache[100][10001];
int dp(int n, int c) {
    if (n < 0) return 0;
    else if (cache[n][c] == -1)
        cache[n][c] = max(dp(n-1, c), c >= cost[n] ? dp(n-1, c-cost[n])+mem[n] : 0);

    return cache[n][c];
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> mem[i];

    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        totalCost += cost[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= 10000; j++)
            cache[i][j] = -1;

    int ret = totalCost;
    for (int c = totalCost; c >= 0; c--)
        if (dp(N-1, c) >= M) ret = c;

    cout << ret << endl;

    return 0;
}
