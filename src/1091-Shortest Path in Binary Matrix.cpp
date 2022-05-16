class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        pair<int, int> curr;
        int N = grid.size();

        if (grid[0][0] || grid[N - 1][N - 1]) return -1;

        grid[0][0] = -1;
        q.push({ 0, 0 });
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int nr, nc, cost = grid[curr.first][curr.second];

            if (curr.first == N - 1 && curr.second == N - 1) return -cost;

            for (int i = 0; i < 8; i++) {
                nr = curr.first + dr[i];
                nc = curr.second + dc[i];

                if (0 <= nr && nr < N && 0 <= nc && nc < N && !grid[nr][nc]) {
                    grid[nr][nc] = cost - 1;
                    q.push({ nr, nc });
                }
            }
        }

        return -1;
    }

private:
    int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
};