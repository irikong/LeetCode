class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, 0x3f3f3f3f)));
        int ret = 0x3f3f3f3f;

        if (houses[0])
            dp[0][houses[0]][1] = 0;
        else
            for (int color = 1; color <= n; color++)
                dp[0][color][1] = cost[0][color - 1];

        for (int i = 1; i < m; i++) {
            if (houses[i]) {
                int color = houses[i];

                for (int prevColor = 1; prevColor <= n; prevColor++) {
                    if (prevColor == color)
                        for (int nb = 1; nb <= target; nb++)
                            dp[i][color][nb] = min(dp[i][color][nb], dp[i - 1][prevColor][nb]);
                    else
                        for (int nb = 1; nb < target; nb++)
                            dp[i][color][nb + 1] = min(dp[i][color][nb + 1], dp[i - 1][prevColor][nb]);
                }
            }
            else {
                for (int color = 1; color <= n; color++) {
                    int currCost = cost[i][color - 1];

                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor == color)
                            for (int nb = 1; nb <= target; nb++)
                                dp[i][color][nb] = min(dp[i][color][nb], dp[i - 1][prevColor][nb] + currCost);
                        else
                            for (int nb = 1; nb < target; nb++)
                                dp[i][color][nb + 1] = min(dp[i][color][nb + 1], dp[i - 1][prevColor][nb] + currCost);
                    }
                }
            }
        }

        for (int color = 1; color <= n; color++)
            ret = min(ret, dp[m - 1][color][target]);

        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};