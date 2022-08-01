class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, 1));

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                path[r][c] = path[r - 1][c] + path[r][c - 1];
            }
        }

        return path[m - 1][n - 1];
    }
};