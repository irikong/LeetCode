class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> len(nums.size());
        int ret = 1;

        for (int i = 0; i < nums.size(); i++) {
            len[i] = 1;

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    len[i] = max(len[i], len[j] + 1);
            }
        }

        for (int l : len)
            if (ret < l) ret = l;

        return ret;
    }
};