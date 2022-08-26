class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> powers;

        for (int i = 0; i < 31; i++) {
            string power = to_string(1 << i);
            sort(power.begin(), power.end());
            powers.insert(power);
        }

        string target = to_string(n);
        sort(target.begin(), target.end());
        auto iter = powers.find(target);

        return iter != powers.end();
    }
};