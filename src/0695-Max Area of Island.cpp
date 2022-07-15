class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        ROW = grid.size();
        COL = grid[0].size();

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 1) {
                    int temp = 0;
                    helper(grid, r, c, temp);
                    ret = max(ret, temp);
                }
            }
        }

        return ret;
    }

private:
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
    int ROW, COL;

    void helper(vector<vector<int>>& grid, int r, int c, int& area) {
        area++;
        grid[r][c] = -1;
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (0 <= nr && nr < ROW && 0 <= nc && nc < COL && grid[nr][nc] == 1) {
                helper(grid, nr, nc, area);
            }
        }
    }
};