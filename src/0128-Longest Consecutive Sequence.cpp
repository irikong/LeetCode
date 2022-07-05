class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> um;
        int ret = 1;

        for (int num : nums) {
            if (um.count(num)) continue;
            
            um[num] = 0x3f3f3f3f;

            if (um.count(num - 1)) {
                um[num] = um[num - 1] == 0x3f3f3f3f ? num - 1 : um[num - 1];
                um[um[num]] = num;
            }

            int small = um[num] == 0x3f3f3f3f ? num : um[num];
            if (um.count(num + 1)) {
                um[small] = um[num + 1] == 0x3f3f3f3f ? num + 1 : um[num + 1];
                um[um[small]] = small;
            }

            if (um[small] != 0x3f3f3f3f) {
                ret = max(ret, um[small] - small + 1);
            }
        }

        return ret;
    }
};