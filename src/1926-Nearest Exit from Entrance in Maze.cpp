class Solution {
public:
    typedef pair<int, int> pii;

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ROW = maze.size();
        int COL = maze[0].size();
        
        queue<pii> q;
        int ret = 0;
        int r = entrance[0];
        int c = entrance[1];
        q.emplace(r, c);
        maze[r][c] = '+';

        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
				r = q.front().first;
				c = q.front().second;
				q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    
                    if (isValidCell(maze, ROW, COL, nr, nc)) {
                        if (nr == 0 || nr == ROW - 1 || nc == 0 || nc == COL - 1)
                            return ret + 1;

                        q.emplace(nr, nc);
                        maze[nr][nc] = '+';
                    }
                }
            }

            ret++;
        }

        return -1;
    }

private:
	int dr[4] = { 0, -1, 0, 1 };
    int dc[4] = { 1, 0, -1, 0 };

    bool isValidCell(vector<vector<char>>& maze, int ROW, int COL, int r, int c) {
        return 0 <= r && r < ROW && 0 <= c && c < COL && maze[r][c] == '.';
    }
};