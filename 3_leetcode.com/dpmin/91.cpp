class Solution {
public:
    int *cache;
    int numDecodings(string s) {
        cache = new int[s.size()];
        
        cache[0] = s[0] != '0' ? 1 : 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') cache[i] = i-2 > 0 ? cache[i-2] : 1;
                else cache[i] = 0;                    
            } else {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) cache[i] = cache[i-1] + (i-2 > 0 ? cache[i-2] : 1);
                else cache[i] = cache[i-1];
            }
            
            if (!cache[i]) {
                cache[s.size()-1] = 0;
                break;
            }
        }
        
        int ret = cache[s.size()-1];
        
        delete []cache;
        
        return ret;
    }
};
