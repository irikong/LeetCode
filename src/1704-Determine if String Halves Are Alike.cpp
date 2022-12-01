class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> us = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        int halfSize = s.size() / 2;
        int cnt = 0;

        for (int i = 0; i < halfSize; i++) {
            if (us.count(s[i])) cnt++;
            if (us.count(s[i + halfSize])) cnt--;
        }

        return cnt == 0;
    }
};