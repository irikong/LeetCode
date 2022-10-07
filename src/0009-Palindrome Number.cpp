class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string sInv(s.rbegin(), s.rend());

        return s == sInv;
    }
};