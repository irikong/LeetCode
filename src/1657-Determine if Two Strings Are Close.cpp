class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        unordered_map<int, int> cntMap;
        int N = word1.size();
        int i = 0, j = 0, prev;
        while (i < N && j < N) {
            if (word1[i] == word2[j]) {
                prev = i;
                while (i < N && word1[i] == word1[prev]) i++;
                cntMap[i - prev]++;

                prev = j;
                while (j < N && word2[j] == word2[prev]) j++;
                cntMap[j - prev]--;
            }
            else return false;
        }
        if (i != j) return false;

        for (auto kv : cntMap) {
            if (kv.second != 0) return false;
        }

        return true;
    }
};