class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int dr[4] = { 0, 1, 0, -1 };
        int dc[4] = { 1, 0, -1, 0 };
        int r = 0, c = 0, dir = 0, lastNum = n * n;

        for (int num = 1; num <= lastNum; num++) {
            matrix[r][c] = num;
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc]) {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }

            r = nr;
            c = nc;
        }

        return matrix;
    }
};