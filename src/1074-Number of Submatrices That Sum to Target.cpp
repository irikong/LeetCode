class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();
        int ret = 0;

        for (int r = 1; r < rSize; r++)
            matrix[r][0] += matrix[r - 1][0];
        for (int c = 1; c < cSize; c++)
            matrix[0][c] += matrix[0][c - 1];
        for (int r = 1; r < rSize; r++)
            for (int c = 1; c < cSize; c++)
                matrix[r][c] += matrix[r - 1][c] + matrix[r][c - 1] - matrix[r - 1][c - 1];

        int plus, minus;
        for (int sr = 0; sr < rSize; sr++) {
            for (int sc = 0; sc < cSize; sc++) {
                plus = (sr && sc) ? matrix[sr - 1][sc - 1] : 0;

                for (int er = sr; er < rSize; er++) {
                    for (int ec = sc; ec < cSize; ec++) {
                        minus = 0;
                        if (sc) minus += matrix[er][sc - 1];
                        if (sr) minus += matrix[sr - 1][ec];

                        if (matrix[er][ec] - minus + plus == target) ret++;
                    }
                }
            }
        }

        return ret;
    }
};