#include <limits>
class Solution {
public:
    int dp(vector<int> &vec, int amt, int* arr){
        int minimum= INT_MAX;

        if(arr[amt]!= -2 ) return arr[amt];

        for(int i =  0; i < vec.size(); i++){
            cout << "amt: " << amt << ":" << arr[amt] << ":" <<vec[i] <<endl;
            if(amt == vec[i]) {
                return arr[amt] = 1;
            }
            if(amt < vec[i]) {
                continue;
            }
            minimum= min(dp(vec, amt-vec[i],arr ), minimum);
        }
        if(minimum == -1 || minimum == INT_MAX) return arr[amt] = -1;
        
        return arr[amt] = minimum +1;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int *arr = new int[amount+1];
        for(int i =  0; i < amount+1; i++){
            arr[i] = -2;
        }
        int tmp = dp(coins, amount, arr);
        
        
        if(tmp == -1) return -1;
        else  return tmp;
    }
};
