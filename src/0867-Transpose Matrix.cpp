class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rSize = matrix.size(), cSize = matrix[0].size();
        vector<vector<int>> ret(cSize, vector<int>(rSize));

        for (int r = 0; r < rSize; r++)
            for (int c = 0; c < cSize; c++)
                ret[c][r] = matrix[r][c];

        return ret;
    }
};