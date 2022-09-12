class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1;
        int ret = 0, score = 0;

        while (l <= r) {
            if (tokens[l] <= power) {
                power -= tokens[l++];
                ret = ++score;
            }
            else {
                if (score) {
                    power += tokens[r--];
                    score--;
                }
                else break;
            }
        }

        return ret;
    }
};