class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> st;

        st.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            
            int top = st.top();
            while (temperatures[top] < temperatures[i]) {
                ret[top] = i - top;
                st.pop();

                if (st.empty()) break;
                else top = st.top();
            }

            st.push(i);
        }

        return ret;
    }
};