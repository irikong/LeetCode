// state
// D -> D 0
// L -> D 1
// D -> L 2
// L -> L 3
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

        int row = board.size();
        int col = board[0].size();

        int liveCnt;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                liveCnt = 0;
                for (int i = 0; i < 8; i++) {
                    int nx = c + dx[i];
                    int ny = r + dy[i];
                    if (0 <= nx && nx < col && 0 <= ny && ny < row && (board[ny][nx] & 1)) {
                        liveCnt++;
                        if (liveCnt > 3) break;
                    }
                }

                if (liveCnt == 3 || (liveCnt == 2 && board[r][c]))
                    board[r][c] += 2;
            }
        }

        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                board[r][c] = board[r][c] > 1 ? 1 : 0;
    }
};