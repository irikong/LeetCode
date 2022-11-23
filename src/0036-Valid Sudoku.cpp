class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> us;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (us.count(board[r][c])) return false;
                
                us.insert(board[r][c]);
            }

            us.clear();
        }

        for (int c = 0; c < 9; c++) {
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.') continue;
                if (us.count(board[r][c])) return false;

                us.insert(board[r][c]);
            }

            us.clear();
        }

        for (int i = 0; i < 9; i++) {
            int offsetRow = 3 * (i / 3);
            int offsetCol = 3 * (i % 3);

            for (int j = 0; j < 9; j++) {
                int r = offsetRow + (j / 3);
                int c = offsetCol + (j % 3);

                if (board[r][c] == '.') continue;
                if (us.count(board[r][c])) return false;

                us.insert(board[r][c]);
            }

            us.clear();
        }

        return true;
    }
};