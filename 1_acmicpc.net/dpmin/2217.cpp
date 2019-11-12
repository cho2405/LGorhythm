#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W[100000];

int main(void) {
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> W[i];
    
    sort(W, W+N);
    
    int ret = 0;
    for (int i = 0; i < N; i++)
        ret = max(ret, W[i] * (N-i));
    
    cout << ret << endl;
    
    return 0;
}
