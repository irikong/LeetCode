class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int iEnd = nums.size() - 2;
        for (int i = 0; i < iEnd; i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }

        return 0;
    }
};