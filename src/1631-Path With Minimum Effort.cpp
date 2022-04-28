class Solution {
private:
    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };
    int ROW, COL;

    bool DFS(const vector<vector<int>>& heights, vector<vector<bool>>& visit, pair<int, int> pos, const int effortLimit) {
        if (pos.first == COL - 1 && pos.second == ROW - 1) return true;

        pair<int, int> nPos;
        for (int dir = 0; dir < 4; dir++) {
            nPos.first = pos.first + dx[dir];
            nPos.second = pos.second + dy[dir];

            if (0 <= nPos.first && nPos.first < COL && 0 <= nPos.second && nPos.second < ROW && !visit[nPos.second][nPos.first]) {
                int diff = abs(heights[nPos.second][nPos.first] - heights[pos.second][pos.first]);

                if (diff <= effortLimit) {
                    visit[nPos.second][nPos.first] = true;
                    if (DFS(heights, visit, nPos, effortLimit)) return true;
                }
            }
        }

        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();

        int l = 0, h = 1e6, m;
        while (l <= h) {
            vector<vector<bool>> visit(ROW, vector<bool>(COL, false));

            m = l + (h - l) / 2;

            if (DFS(heights, visit, { 0, 0 }, m))
                h = m - 1;
            else
                l = m + 1;
        }

        return h + 1;
    }
};