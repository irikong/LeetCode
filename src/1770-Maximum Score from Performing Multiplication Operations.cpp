class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int ret = -0x3f3f3f3f;
        int nSize = nums.size();
        int mSize = multipliers.size();
        vector<int> dp(mSize + 1, 0);

        dp[0] = multipliers[0] * nums.back();
        dp[1] = multipliers[0] * nums[0];
		for (int i = 2; i <= mSize; i++) {
            int mult = multipliers[i - 1];

            dp[i] = dp[i - 1] + mult * nums[i - 1];
            for (int j = i - 1; j > 0; j--) {
                dp[j] = max(dp[j - 1] + mult * nums[j - 1], dp[j] + mult * nums[nSize + (j - i)]);
			}
            dp[0] += mult * nums[nSize - i];
		}

        for (int num : dp)
            ret = max(ret, num);

        return ret;
    }
};