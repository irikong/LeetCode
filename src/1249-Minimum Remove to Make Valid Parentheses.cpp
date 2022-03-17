class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push({ s[i], i });
            }
            else if (s[i] == ')') {
                if (!stack.empty() && stack.top().first == '(') {
                    stack.pop();
                }
                else {
                    stack.push({ s[i], i });
                }
            }
        }

        while (!stack.empty()) {
            s[stack.top().second] = ' ';
            stack.pop();
        }

        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        return s;
    }
};