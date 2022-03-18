class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> cnt;
        for (const char& c : s) {
            cnt[c]++;
        }

        unsigned int mask = 0;
        stack<char> cStack;
        for (const char& c : s) {
            cnt[c]--;

            if (mask & (1 << (c - 'a'))) {
                continue;
            }
            else {
                while (!cStack.empty() && cStack.top() > c && cnt[cStack.top()]) {
                    mask ^= (1 << (cStack.top() - 'a'));
                    cStack.pop();
                }

                cStack.push(c);
                mask |= (1 << (cStack.top() - 'a'));
            }
        }

        string rev;
        while (!cStack.empty()) {
            rev.push_back(cStack.top());
            cStack.pop();
        }
        reverse(rev.begin(), rev.end());
        return rev;
    }
};