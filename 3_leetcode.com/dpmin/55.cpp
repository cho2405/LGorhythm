class Solution {
public:
    bool canJump(vector<int>& nums) {        
        bool *avail = new bool[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            avail[i] = false;
        
        avail[0] = true;
        for (int i = 0; i < nums.size(); i++) {            
            if (avail[i]) {
                if (i+nums[i] >= nums.size()-1) {
                    avail[nums.size()-1] = true;
                    break;
                } else {
                    for (int j = i+1; j <= i+nums[i]; j++)
                        avail[j] = true;
                }
            }
        }
        
        bool ret = avail[nums.size()-1];
        delete []avail;        
        return ret;
    }
};
