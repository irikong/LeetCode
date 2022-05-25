class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2) {
			return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] > v2[1];
			});

		vector<int> dp;

		for (vector<int>& envelope : envelopes) {
			int key = envelope[1];
			int idx = lower_bound(dp.begin(), dp.end(), key) - dp.begin();

			if (idx == dp.size())
				dp.push_back(key);

			dp[idx] = key;
		}

		return dp.size();
	}
};