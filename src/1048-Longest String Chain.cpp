class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> um;
        int ret = 1;

        for (const string& word : words)
            um[word] = 1;

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() != b.size() ? a.size() > b.size() : a > b;
            });

        for (const string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                string w = word;
                w.erase(i, 1);

                if (um.count(w)) um[w] = max(um[w], um[word] + 1);
            }
        }

        for (const auto& kv : um)
            if (ret < kv.second) ret = kv.second;

        return ret;
    }
};