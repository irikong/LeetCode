class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int minNum = 0x3f3f3f3f, maxNum = -0x3f3f3f3f, l = -1, r = -1;

		for (int i = nums.size() - 1; i >= 0; i--) {
			if (minNum > nums[i]) minNum = nums[i];
			if (minNum != nums[i]) l = i;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (maxNum < nums[i]) maxNum = nums[i];
			if (maxNum != nums[i]) r = i;
		}

		return (l == r ? 0 : r - l + 1);
	}
};