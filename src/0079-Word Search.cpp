class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == word[0] && Helper(board, word, 1, r, c))
                    return true;
            }
        }

        return false;
    }

private:
    int dr[4] = { 0, -1, 0, 1 };
    int dc[4] = { 1, 0, -1, 0 };
    int ROW;
    int COL;

    bool Helper(vector<vector<char>>& board, const string& word, int idx, int r, int c) {
        if (idx == word.size()) return true;
        
        bool ret = false;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (0 <= nr && nr < ROW && 0 <= nc && nc < COL && board[nr][nc] == word[idx]) {
                board[r][c] += 100; // 100: for visit check
                ret |= Helper(board, word, idx + 1, nr, nc);
                board[r][c] -= 100;
            }
        }

        return ret;
    }
};