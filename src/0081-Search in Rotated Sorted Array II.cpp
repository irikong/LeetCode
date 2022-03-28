class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ret = false;
        int l = 0, r = nums.size() - 1, m;

        while (l <= r) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;

            m = l + (r - l) / 2;
            if (nums[m] == target) {
                ret = true;
                break;
            }
            else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else {
                if (nums[m] <= target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return ret;
    }
};