class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int dist = 'a' - 'A';
        for (char c : s) {
            if (!st.empty() && (abs(c - st.top()) == dist))
                st.pop();
            else
                st.push(c);
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