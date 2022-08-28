class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rSize = mat.size(), cSize = mat[0].size();
        
        for (int sc = 0; sc < cSize; sc++) {
            vector<int> diagonal;
            int r = 0, c = sc;

            while (r < rSize && c < cSize) {
                diagonal.push_back(mat[r++][c++]);
            }

            sort(diagonal.begin(), diagonal.end());
            r = 0, c = sc;
            for (int sortedNum : diagonal) {
                mat[r++][c++] = sortedNum;
            }
        }

        for (int sr = 1; sr < rSize; sr++) {
            vector<int> diagonal;
            int r = sr, c = 0;

            while (r < rSize && c < cSize) {
                diagonal.push_back(mat[r++][c++]);
            }

            sort(diagonal.begin(), diagonal.end());
            r = sr, c = 0;
            for (int sortedNum : diagonal) {
                mat[r++][c++] = sortedNum;
            }
        }

        return mat;
    }
};