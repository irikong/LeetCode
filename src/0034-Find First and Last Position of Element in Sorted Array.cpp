class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int start = -1, end = -1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else {
                start = m;
                r = m - 1;
            }
        }

        if (start != -1) {
            l = start, r = nums.size() - 1;

            while (l <= r) {
                int m = (l + r) / 2;

                if (nums[m] > target)
                    r = m - 1;
                else {
                    end = m;
                    l = m + 1;
                }
            }
        }

        return { start, end };
    }
};