class Solution {
public:
    string reverseVowels(string s) {
		unordered_set<char> us{ 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && us.count(s[l]) == 0) l++;
            while (l < r && us.count(s[r]) == 0) r--;
            swap(s[l++], s[r--]);
        }

        return s;
    }
};