class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;
    
        vector<int> maxCache, minCache;
        maxCache.push_back(nums[0]);
        minCache.push_back(nums[0]);
        
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpMax = max(nums[i], max(maxCache.back()*nums[i], minCache.back()*nums[i]));
            int tmpMin = min(nums[i], min(maxCache.back()*nums[i], minCache.back()*nums[i]));
            
            maxCache.push_back(tmpMax);
            minCache.push_back(tmpMin);
            
            ret = max(max(ret, tmpMax), tmpMin);
        }

        return ret;
    }
};
