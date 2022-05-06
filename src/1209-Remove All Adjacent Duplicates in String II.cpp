class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> strStack;
        string ret;

        pair<char, int> tp;
        for (char c : s) {
            if (strStack.empty() || strStack.top().first != c) {
                strStack.push({ c, 1 });
            }
            else {
                tp = strStack.top();
                strStack.pop();

                if (tp.second < k - 1) {
                    tp.second++;
                    strStack.push(tp);
                }
            }
        }

        while (!strStack.empty()) {
            tp = strStack.top();
            ret.append(tp.second, tp.first);
            strStack.pop();
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};