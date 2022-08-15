class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbolValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int before = symbolValue[s.back()];
        int ret = before;
        for (int i = s.size() - 2; i >= 0; i--) {
            int curr = symbolValue[s[i]];
            if (curr < before) ret -= curr;
            else ret += curr;

            before = curr;
        }

        return ret;
    }
};