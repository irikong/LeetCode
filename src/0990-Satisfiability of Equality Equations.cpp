class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> alpha(26);
        for (int i = 0; i < alpha.size(); i++) {
            alpha[i] = i;
        }

        for (const string& s : equations) {
            if (s[1] == '=') {
                alpha[GetRoot(alpha, s[3])] = GetRoot(alpha, s[0]);
            }
        }

        for (const string& s : equations) {
            if (s[1] == '!' && (GetRoot(alpha, s[0]) == GetRoot(alpha, s[3]))) return false;
        }

        return true;
    }

private:
    int GetRoot(const vector<int>& alpha, char c) {
        int idx = c - 'a';

        while (alpha[idx] != idx) {
            idx = alpha[idx];
        }

        return idx;
    }
};