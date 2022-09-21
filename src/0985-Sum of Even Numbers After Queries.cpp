class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ret;

        int sum = 0;
        for (int num : nums) {
            if (!(num & 1))
                sum += num;
        }

        for (vector<int>& query : queries) {
            int idx = query[1];

            if(!(nums[idx] & 1))
                sum -= nums[idx];

            nums[idx] += query[0];
            
            if (!(nums[idx] & 1))
                sum += nums[idx];

            ret.push_back(sum);
        }

        return ret;
    }
};