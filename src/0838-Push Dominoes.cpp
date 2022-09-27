class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> left(dominoes.size(), 0x3f3f3f3f);
        vector<int> right(dominoes.size(), 0x3f3f3f3f);

        bool isFalling = dominoes[0] == 'R';
        if (isFalling) right[0] = 0;
        for (int i = 1; i < dominoes.size(); i++) {
            if (dominoes[i] == 'R') {
                isFalling = true;
                right[i] = 0;
            }
            else if (dominoes[i] == 'L') {
                isFalling = false;
            }
            else if (dominoes[i] == '.' && isFalling) {
                right[i] = right[i - 1] + 1;
            }
        }

        isFalling = dominoes.back() == 'L';
        if (isFalling) left.back() = 0;
        for (int i = dominoes.size() - 1; i >= 0; i--) {
            if (dominoes[i] == 'R') {
                isFalling = false;
            }
            else if (dominoes[i] == 'L') {
                isFalling = true;
                left[i] = 0;
            }
            else if (dominoes[i] == '.' && isFalling) {
                left[i] = left[i + 1] + 1;
            }
        }

        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == '.') {
                if (left[i] > right[i]) dominoes[i] = 'R';
                else if (left[i] < right[i]) dominoes[i] = 'L';
            }
        }

        return dominoes;
    }
};