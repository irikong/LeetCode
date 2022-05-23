class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int zero, one;
        for (const string& str : strs) {
            zero = one = 0;

            for (const char& c : str) {
                if (c == '0') zero++;
                else one++;
            }

            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    if (dp[i][j] < dp[i - zero][j - one] + 1)
                        dp[i][j] = dp[i - zero][j - one] + 1;
                }
            }
        }

        return dp[m][n];
    }
};