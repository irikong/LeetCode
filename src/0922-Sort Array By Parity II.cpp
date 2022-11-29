class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;

        while (odd < nums.size()) {
            while (odd < nums.size() && (nums[odd] & 1))
                odd += 2;
            while (even < nums.size() && !(nums[even] & 1))
                even += 2;

            if(odd < nums.size())
                swap(nums[even], nums[odd]);

            even += 2;
            odd += 2;
        }

        return nums;
    }
};