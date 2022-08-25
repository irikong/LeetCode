class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alpha[26] = {0, };

        for (char& c : magazine) {
            alpha[c - 'a']++;
        }

        for (char& c : ransomNote) {
            int idx = c - 'a';
            if (0 < alpha[idx]) alpha[idx]--;
            else return false;
        }

        return true;
    }
};