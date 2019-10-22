#include <iostream>

using namespace std;
#define MAX 101
double m[MAX];
double c[MAX];

int N, M;
double result = 10000001;

void dp(int n, double m_sum, double c_sum) {
    if(m_sum >= M) {
        if(result > c_sum)
            result = c_sum;
        return;
    }
    if( n == -1){
        return;
    }
    dp(n-1, m_sum+m[n], c_sum+c[n]);
    dp(n-1, m_sum, c_sum);
}
int main() {
    cin >> N >> M;
    int i=0;
    for(int i = 0; i < N; i++) {
        cin >> m[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> c[i];
    }
    dp(N-1, 0, 0);

    cout << result << endl;
    return 0;
}
