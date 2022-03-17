class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> stack;

        for (const char& c : s) {
            if (c == '(') stack.push(0);
            else {
                int sum = 0;
                while (stack.top() != 0) {
                    sum += stack.top();
                    stack.pop();
                }

                stack.pop();
                stack.push((!sum ? 1 : 2 * sum));
            }
        }

        while (!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        return ans;
    }
};