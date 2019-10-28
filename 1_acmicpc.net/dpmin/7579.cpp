#include <iostream>
#include <climits>
#include <map>

using namespace std;

unsigned int N, M;
unsigned int mem[100];
unsigned int cost[100];

map<unsigned int, unsigned int> cache[100];
int dp(int n, int m) {
    if (m <= 0) return 0;
    else if (n < 0) return INT_MAX;
    else {
        auto it = cache[n].find(m);
        if (it == cache[n].end()) {
            unsigned int minV = dp(n-1, m);
            for (int i = 1; i <= mem[n]; i++)
                minV = min(minV, dp(n-1, m-i)+cost[n]);
        
            cache[n][m] = minV;
            return minV;
        }
        
        return it->second;
    }
    
    return 0;
}

int main(void) {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        cin >> mem[i];
        
    for (int i = 0; i < N; i++)
        cin >> cost[i];
        
    cout << dp(N-1, M) << endl;
    
    return 0;
}
