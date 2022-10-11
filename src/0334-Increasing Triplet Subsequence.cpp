class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> triplet(2, numeric_limits<int>::max());

        for (int num : nums) {
            if (num <= triplet[0]) triplet[0] = num;
            else if (num <= triplet[1]) triplet[1] = num;
            else return true;
        }

        return false;
    }
};