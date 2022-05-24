class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ret = 0;

        for (const char& c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int temp = 0;

                while (!st.empty()) {
                    if (st.top()) {
                        temp += st.top();
                        st.pop();
                    }
                    else {
                        temp += 2;
                        st.top() = temp;
                        break;
                    }
                }

                if (ret < temp) ret = temp;
            }
        }

        int sum = 0;
        while (!st.empty()) {
            if (st.top()) {
                sum += st.top();

                if (ret < sum) ret = sum;
            }
            else
                sum = 0;

            st.pop();
        }

        return ret;
    }
};