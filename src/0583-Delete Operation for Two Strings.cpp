class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        vector<vector<int>> LCS(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }

        return size1 + size2 - 2 * LCS[size1][size2];
    }
};