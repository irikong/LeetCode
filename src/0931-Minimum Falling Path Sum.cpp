class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();

        for (int r = 1; r < rSize; r++) {
            for (int c = 0; c < cSize; c++) {
                int s = max(c - 1, 0);
                int e = min(c + 1, cSize - 1);
                int minNum = 0x3f3f3f3f;
                while (s <= e) {
                    minNum = min(minNum, matrix[r - 1][s++]);
                }

                matrix[r][c] += minNum;
            }
        }

        return *min_element(matrix[rSize - 1].begin(), matrix[rSize - 1].end());
    }
};