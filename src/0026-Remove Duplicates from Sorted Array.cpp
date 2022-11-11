class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currNum = nums[0];
        int backIdx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != currNum) {
                currNum = nums[i];
                nums[++backIdx] = currNum;
            }
        }

        return ++backIdx;
    }
};