class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        for (int r = 1; r <= s1.size(); r++) {
            if (s1[r - 1] == s3[r - 1]) dp[r][0] = r - 1;
            else break;
        }
        for (int c = 1; c <= s2.size(); c++) {
            if (s2[c - 1] == s3[c - 1]) dp[0][c] = c - 1;
            else break;
        }

        for (int r = 1; r <= s1.size(); r++) {
            for (int c = 1; c <= s2.size(); c++) {
                if (dp[r][c - 1] != -1) {
                    int i = dp[r][c - 1] + 1;

                    if (s3[i] == s2[c - 1]) dp[r][c] = i;
                }
                else if (dp[r - 1][c] != -1) {
                    int i = dp[r - 1][c] + 1;

                    if (s3[i] == s1[r - 1]) dp[r][c] = i;
                }
            }
        }

        return dp[s1.size()][s2.size()] == s3.size() - 1;
    }
};