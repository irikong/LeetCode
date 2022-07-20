class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		int ret = 0;
		vector<vector<int>> indices(26, vector<int>());

		for (int i = 0; i < s.size(); i++) {
			indices[CharToIndex(s[i])].push_back(i);
		}

		for (const string& word : words) {
			int prev = -1;
			bool isOK = true;

			for (char c : word) {
				int idx = CharToIndex(c);

				auto it = upper_bound(indices[idx].begin(), indices[idx].end(), prev);
				if (it == indices[idx].end()) {
					isOK = false;
					break;
				}
				else prev = *it;
			}

			if (isOK) ret++;
		}

		return ret;
	}

private:
	int CharToIndex(char c) {
		return c - 'a';
	}
};