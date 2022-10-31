class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int ROW = matrix.size();
        const int COL = matrix[0].size();

        for (int r = 1; r < ROW; r++) {
            for (int c = 1; c < COL; c++) {
                if (matrix[r][c] != matrix[r - 1][c - 1])
                    return false;
            }
        }

        return true;
    }
};