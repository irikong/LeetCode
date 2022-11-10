class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty() || st.top() != c)
                st.push(c);
            else
                st.pop();
        }

        string ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};