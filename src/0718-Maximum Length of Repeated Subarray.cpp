class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums2.size() + 1, vector<int>(nums1.size() + 1, 0));
        int ret = 0;

        for (int i = 0; i < nums2.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    ret = max(ret, dp[i + 1][j + 1]);
                }
            }
        }

        return ret;
    }
};