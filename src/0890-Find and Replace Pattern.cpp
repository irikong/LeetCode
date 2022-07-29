class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        int wordSize = pattern.size();
        vector<int> pat(wordSize, -1);

        for (int i = 0; i < wordSize; i++) {
            if (pat[i] == -1) {
                pat[i] = i;

                for (int j = i + 1; j < wordSize; j++) {
                    if (pattern[i] == pattern[j])
                        pat[j] = i;
                }
            }
        }

        for (const string& word : words) {
            bool same = true;
            unordered_map<char, int> um;

            for (int i = 0; i < wordSize; i++) {
				if (um.count(word[i])) {
                    if (um[word[i]] != pat[i]) {
                        same = false;
                        break;
                    }
				}
				else {
					um[word[i]] = pat[i];
				}

                if (word[i] != word[pat[i]]) {
                    same = false;
                    break;
                }
            }

            if (same) ret.emplace_back(word);
        }

        return ret;
    }
};