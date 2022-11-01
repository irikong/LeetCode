class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        vector<int> ret(COL, -1);

        queue<pair<int, int>> q; // ballNum, col
        for (int ballNum = 0; ballNum < COL; ballNum++) {
            q.emplace(ballNum, ballNum);
        }

        int ballNum, c;
        for (int r = 0; r < ROW; r++) {
            if (q.empty()) break;
            
            int qSize = q.size();
            while (qSize--) {
                ballNum = q.front().first;
                c = q.front().second;
                q.pop();

                if (grid[r][c] == 1) {
                    if (!(c == COL - 1) && (grid[r][c + 1] == 1))
                        q.emplace(ballNum, c + 1);
                }
                else {
                    if (!(c == 0) && (grid[r][c - 1] == -1))
                        q.emplace(ballNum, c - 1);
                }
            }
        }

        while (!q.empty()) {
            ret[q.front().first] = q.front().second;
            q.pop();
        }

        return ret;
    }
};