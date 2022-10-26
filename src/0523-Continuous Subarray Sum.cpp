class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> modSet;
        
        int sum = 0, mod, preMod = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mod = sum % k;
            if (modSet.count(mod)) {
                return true;
            }

            modSet.insert(preMod);
            preMod = mod;
        }

        return false;
    }
};