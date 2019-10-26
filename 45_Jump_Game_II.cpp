class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 1;
        if(nums.size() < 2)
            return 0;
        int thisstepmax = nums[0];
        if(nums[0] >= nums.size() - 1)
            return 1;
        int nextstepmax = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(i + nums[i] >= nums.size() - 1)
                return step + 1;
            if(i + nums[i] > nextstepmax)
                nextstepmax = i + nums[i];
            if(i == thisstepmax)
            {
                ++step;
                thisstepmax = nextstepmax;
            }
        }
        return 0;
    }
};
