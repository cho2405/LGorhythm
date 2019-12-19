#define MAX 1000000
#include <limits>

class Solution {
public:
    int arr[MAX][2];
    int maximum(int x, int y, int z){
        if (x>y)
            if (x>z)
                return x;
            else
                return z;
        else
            if (y>z)
                return y;
            else
                return z;
    }

    int min_three(int x, int y, int z){
      return x < y ? (x < z ? x : z) : (y < z ? y : z);
    }

    int maxProduct(vector<int>& nums) {
        int max_value = nums[0];
        
        arr[0][0]=nums[0];
        arr[0][1]=nums[0];
        for(int i = 1; i < nums.size(); i++) {
            arr[i][0] = maximum(arr[i-1][1]*nums[i], nums[i] * arr[i-1][0],  nums[i]);
            arr[i][1] = min_three(arr[i-1][1]*nums[i], nums[i] * arr[i-1][0],  nums[i]);
            max_value = maximum(max_value, arr[i][0], arr[i][1]);
        }
        return max_value;
    }
};
