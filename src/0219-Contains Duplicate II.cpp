class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int iEnd = min(static_cast<int>(nums.size()), k);
        for (int i = 0; i < iEnd; i++) {
            if (um[nums[i]]) return true;
            um[nums[i]]++;
        }

        for (int i = k; i < nums.size(); i++) {
            if (um[nums[i]]) return true;
            um[nums[i - k]]--;
            um[nums[i]]++;
        }

        return false;
    }
};