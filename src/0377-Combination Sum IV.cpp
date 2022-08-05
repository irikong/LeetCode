class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned int> dp(target + 1, 0);

		sort(nums.begin(), nums.end());
		dp[0] = 1;

		for (int t = 1; t <= target; ++t) {
			for (int num : nums) {
				if (num <= t) dp[t] += dp[t - num];
				else break;
			}
		}

		return dp[target];
	}
};