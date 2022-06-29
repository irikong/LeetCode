class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
		});

		vector<vector<int>> ret(people.size(), vector<int>());

		for (const vector<int>& p : people) {
			int eCnt = 0;

			for (int i = 0; i < ret.size(); i++) {
				if (ret[i].empty()) {
					if (eCnt == p[1]) {
						ret[i] = p;
						break;
					}

					eCnt++;
				}
			}
		}

		return ret;
	}
};