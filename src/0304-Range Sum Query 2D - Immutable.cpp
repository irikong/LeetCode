class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        rSize = mat.size();
        cSize = mat[0].size();

        for (int r = 1; r < rSize; r++)
            mat[r][0] += mat[r - 1][0];
        for (int c = 1; c < cSize; c++)
            mat[0][c] += mat[0][c - 1];

        for (int r = 1; r < rSize; r++) {
            for (int c = 1; c < cSize; c++) {
                mat[r][c] += mat[r - 1][c] + mat[r][c - 1] - mat[r - 1][c - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = mat[row2][col2];
        if (0 < col1) ret -= mat[row2][col1 - 1];
        if (0 < row1) ret -= mat[row1 - 1][col2];
        if (0 < col1 && 0 < row1) ret += mat[row1 - 1][col1 - 1];
        
        return ret;
    }

private:
    vector<vector<int>> mat;
    int rSize;
    int cSize;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */