class Solution {
public:
    int *cache;
           
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;            
        else if (cache[amount] == -1) {
            cache[amount] = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
                if (amount-coins[i] >= 0)
                    cache[amount] = min(cache[amount], dp(coins, amount-coins[i]));
            cache[amount] += cache[amount] == INT_MAX ? 0 : 1;
        }
        
        return cache[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {        
        cache = new int[amount+1];
        for (int i = 0; i <= amount; i++)
            cache[i] = -1;
        
        int ret = dp(coins, amount);                
        
        delete []cache;
        
        return ret != INT_MAX ? ret : -1;
    }
};
