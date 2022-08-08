class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int ret = 1;

        lis.push_back(nums[0]);

        vector<int>::iterator it;
        for (int i = 1; i < nums.size(); i++) {
            it = lower_bound(lis.begin(), lis.end(), nums[i]);
        
            if (it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return lis.size();
    }
};