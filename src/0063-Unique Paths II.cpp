class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rSize = obstacleGrid.size();
        cSize = obstacleGrid[0].size();

        if (obstacleGrid[0][0] || obstacleGrid[rSize - 1][cSize - 1]) return 0;

        vector<vector<int>> numPath(rSize + 1, vector<int>(cSize + 1, 0));
        numPath[1][1] = 1;

        for (int r = 1; r <= rSize; r++) {
            for (int c = 1; c <= cSize; c++) {
                if (!obstacleGrid[r - 1][c - 1])
                    numPath[r][c] += numPath[r - 1][c] + numPath[r][c - 1];
            }
        }

        return numPath[rSize][cSize];
    }

private:
    int rSize;
    int cSize;
};