class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rSize = triangle.size();
        int ret = 0x3f3f3f3f;

        for (int r = 1; r < rSize; r++) {
            triangle[r][0] += triangle[r - 1][0];
            triangle[r][r] += triangle[r - 1][r - 1];

            for (int c = 1; c < r; c++)
                triangle[r][c] += min(triangle[r - 1][c - 1], triangle[r - 1][c]);
        }

        for (int sum : triangle[rSize - 1])
            if (sum < ret) ret = sum;

        return ret;
    }
};