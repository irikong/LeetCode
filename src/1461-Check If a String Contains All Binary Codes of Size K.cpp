class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (k << 1)) return false;
        
        unordered_set<string> us;

        int end = s.size() - k;
        for (int i = 0; i <= end; i++) {
            us.insert(s.substr(i, k));
        }

        return us.size() == pow(2, k);
    }
};