class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    lcs[i + 1][j + 1] = lcs[i][j] + 1;
                }
                else {
                    lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
                }
            }
        }

        return lcs[text1.size()][text2.size()];
    }
};