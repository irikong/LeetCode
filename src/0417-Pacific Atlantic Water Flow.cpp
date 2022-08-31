class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rSize = heights.size();
        cSize = heights[0].size();
        vector<vector<int>> visit(rSize, vector<int>(cSize, 0));

        for (int c = 0; c < cSize; c++) {
            if(!(visit[0][c] & Pacific))
                DFS(heights, visit, 0, c, Pacific);
            if(!(visit[rSize - 1][c] & Atlantic))
                DFS(heights, visit, rSize - 1, c, Atlantic);
        }
        for (int r = 0; r < rSize; r++) {
            if (!(visit[r][0] & Pacific))
                DFS(heights, visit, r, 0, Pacific);
            if (!(visit[r][cSize - 1] & Atlantic))
                DFS(heights, visit, r, cSize - 1, Atlantic);
        }

        vector<vector<int>> ret;
        for (int r = 0; r < rSize; r++) {
            for (int c = 0; c < cSize; c++) {
                if (visit[r][c] == Both) {
                    ret.push_back({ r, c });
                }
            }
        }

        return ret;
    }

private:
    const int Pacific = 0b01;
    const int Atlantic = 0b10;
    const int Both = 0b11;
    const int dr[4] = { 0, 0, 1, -1 };
    const int dc[4] = { 1, -1, 0, 0 };

    int rSize;
    int cSize;

    void DFS(const vector<vector<int>>& heights, vector<vector<int>>& visit, int r, int c, const int& ocean) {
        visit[r][c] |= ocean;
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (0 <= nr && nr < rSize && 0 <= nc && nc < cSize && !(visit[nr][nc] & ocean) && heights[r][c] <= heights[nr][nc]) {
                DFS(heights, visit, nr, nc, ocean);
            }
        }
    }
};