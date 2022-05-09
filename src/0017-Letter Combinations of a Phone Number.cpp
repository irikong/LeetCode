class Solution {
private:
    vector<string> digitToLetter = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ret;
        queue<string> q;

        for (char& c : digitToLetter[digits[0] - '0']) {
            q.push(string(1, c));
        }

        int currLen = 1;
        while (currLen != digits.size()) {
            int size = q.size();
            string nextLetter = digitToLetter[digits[currLen] - '0'];

            while (size--) {
                for (char c : nextLetter) {
                    q.push(q.front() + c);
                }
                q.pop();
            }

            currLen++;
        }

        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }
};