class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;

        for (int r = 0; r < numRows; r++) {
            vector<int> v = { 1 };
            for (int c = 1; c < r; c++) {
                v.push_back(ret[r - 1][c - 1] + ret[r - 1][c]);
            }
            v.push_back(1);

            ret.push_back(v);
        }

        ret[0].pop_back();
        return ret;
    }
};