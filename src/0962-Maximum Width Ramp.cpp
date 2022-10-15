class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ret = 0;
        stack<pair<int, int>> st;

        st.emplace(nums[0], 0);
        for (int i = 1; i < nums.size(); i++) {
            if (st.top().first > nums[i]) {
                st.emplace(nums[i], i);
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= nums[i]) {
                ret = max(ret, i - st.top().second);
                st.pop();
            }
        }

        return ret;
    }
};