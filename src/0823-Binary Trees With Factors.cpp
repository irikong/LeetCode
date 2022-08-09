class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = pow(10, 9) + 7;
        int ret = 0;
        unordered_map<int, long long> dp;

        sort(arr.begin(), arr.end());

        for (int num : arr) {
            dp[num] = 1;

            for (int i = 0; arr[i] < num; i++) {
                if ((num % arr[i]) || (!dp.count(num / arr[i]))) continue;

                dp[num] += (dp[arr[i]] * dp[num / arr[i]]) % mod;
                dp[num] %= mod;
            }
        }

        for (const auto& it : dp) {
            ret += it.second;
            ret %= mod;
        }

        return ret;
    }
};