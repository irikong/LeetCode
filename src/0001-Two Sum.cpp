class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> m;

        int diff;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if (m.count(diff)) {
                ans = { m[diff], i };
                break;
            }
            else {
                m[nums[i]] = i;
            }
        }

        return ans;
    }
};