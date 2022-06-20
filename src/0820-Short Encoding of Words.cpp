class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		Trie trie;

		sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
			return s1.size() == s2.size() ? s1 < s2 : s1.size() > s2.size();
			});

		for (const string& word : words)
			trie.Insert(word);

		return trie.cnt + trie.len;
	}

private:
	struct TrieNode
	{
		char data;
		unordered_map<char, TrieNode*> next;

		TrieNode(char c = ' ') : data(c) {};
	};

	struct Trie {
		TrieNode* root;
		int cnt;
		int len;

		Trie() : cnt(0), len(0) {
			root = new TrieNode();
		}

		void Insert(string s) {
			bool isNew = false;
			TrieNode* node = root;

			for (int i = s.size() - 1; i >= 0; i--) {
				char c = s[i];

				if (node->next.count(c)) {
					node = node->next[c];
				}
				else {
					TrieNode* newNode = new TrieNode(c);
					node->next[c] = newNode;
					node = newNode;

					isNew = true;
				}
			}

			if (isNew) {
				cnt++;
				len += s.size();
			}
		}
	};
};