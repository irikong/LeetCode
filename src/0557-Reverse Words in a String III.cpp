class Solution {
public:
    string reverseWords(string s) {
        int b = 0, e;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                e = i;
                reverse(s.begin() + b, s.begin() + e);
                b = i + 1;
            }
        }
        reverse(s.begin() + b, s.end());

        return s;
    }
};