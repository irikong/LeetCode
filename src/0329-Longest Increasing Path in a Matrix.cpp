class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		rSize = matrix.size();
		cSize = matrix[0].size();

		vector<vector<int>> visit(rSize, vector<int>(cSize, 0));
		int ret = 1;

		for (int r = 0; r < rSize; r++) {
			for (int c = 0; c < cSize; c++) {
				if (!visit[r][c]) {
					DFS(matrix, visit, r, c);

					if (ret < visit[r][c])
						ret = visit[r][c];
				}
			}
		}

		return ret;
	}

private:
	const int dr[4] = { -1, 0, 0, 1 };
	const int dc[4] = { 0, -1, 1, 0 };
	int rSize;
	int cSize;

	void DFS(const vector<vector<int>>& matrix, vector<vector<int>>& visit, int r, int c) {
		visit[r][c] = 1;

		int nr, nc;
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];

			if (0 <= nr && nr < rSize && 0 <= nc && nc < cSize && matrix[r][c] < matrix[nr][nc]) {
				if (!visit[nr][nc])
					DFS(matrix, visit, nr, nc);

				if (visit[r][c] < visit[nr][nc] + 1)
					visit[r][c] = visit[nr][nc] + 1;
			}
		}
	}
};