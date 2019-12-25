class Solution {
public:
    int *cache;
    void init(int n) {
        cache = new int[n+1];
        for (int i = 1; i <= n; i++)
            cache[i] = 0;
    }
    
    void final() {
        delete []cache;
    }
    
    int dp(int n) {
        if (n <= 1) return n;
        else if (!cache[n]) {
            cache[n] = INT_MAX;              
            for (int i = 1; i <= sqrt(n); i++)
                cache[n] = min(cache[n], dp(n-(i*i))+1);            
        }
        
        return cache[n];
    }
    
    int numSquares(int n) {
        init(n);                
        int ret = dp(n);
        final();
        
        return ret;
    }
};
