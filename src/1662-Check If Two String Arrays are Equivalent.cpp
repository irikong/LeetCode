class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for (string& s : word1) {
            a.append(s);
        }
        for (string& s : word2) {
            b.append(s);
        }

        return a == b;
    }
};