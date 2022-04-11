class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int total = row * col;
        vector<vector<int>> newGrid(row, vector<int>(col, 0));

        k %= total;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                int idx = (r * col + c + k) % total;
                newGrid[idx / col][idx % col] = grid[r][c];
            }
        }

        return newGrid;
    }
};