class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(nums.size(), 0);
        
        for (int i = 0; i < n; i++) {
            ret[2 * i] = nums[i];
            ret[2 * i + 1] = nums[i + n];
        }

        return ret;
    }
};