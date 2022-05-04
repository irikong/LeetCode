class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, ret = 0;
        sort(nums.begin(), nums.end());

        int sum;
        while (l < r) {
            sum = nums[l] + nums[r];

            if (sum < k)
                l++;
            else if (sum > k)
                r--;
            else {
                ret++;
                l++;
                r--;
            }
        }

        return ret;
    }
};