class Solution {
public:
    int splitArray(vector<int> nums, int m) {
        vector<vector<int>> dp(m + 1, vector<int>(nums.size(), 0));

        dp[1][0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[1][i] = dp[1][i - 1] + nums[i];
        }

        for (int mCnt = 2; mCnt <= m; mCnt++) {
            int minJ = mCnt - 2;

            for (int i = mCnt - 1; i < nums.size(); i++) {
                int minSum = 0x3f3f3f3f, temp;

                for (int j = i - 1; j >= minJ; j--) {
                    temp = max(dp[mCnt - 1][j], dp[1][i] - dp[1][j]);

                    if (temp <= minSum) minSum = temp;
                    else break;
                }

                dp[mCnt][i] = minSum;
            }
        }

        return dp[m][nums.size() - 1];
    }
};