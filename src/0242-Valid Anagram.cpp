class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int alpha[26] = { 0, };

        for (char& c : s) {
            alpha[c - 'a']++;
        }

        for (char& c : t) {
            if (0 < alpha[c - 'a']) {
                alpha[c - 'a']--;
            }
            else
                return false;
        }

        return true;
    }
};