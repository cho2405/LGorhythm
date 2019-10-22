#include <iostream>
#include <algorithm>

#define MAX 100000
using namespace std;
int N;

int arr[MAX];

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int result = 0;
    for(int i = 0; i < N; i++) {
        int temp = arr[i] * (N-i);
        if( temp > result)
            result = temp;
    }
    cout << result << endl;
    return 0;
}
