class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        bool ans = true;
        bool check[1001] = { false, };
        stack<int> s;

        int idx = 0;
        for (int target : popped) {
            if (check[target]) {
                if (s.top() == target) {
                    s.pop();
                    check[target] = false;
                }
                else {
                    ans = false;
                    break;
                }
            }
            else {
                while (target != pushed[idx]) {
                    check[pushed[idx]] = true;
                    s.push(pushed[idx]);
                    idx++;
                }

                idx++;
            }
        }

        return ans;
    }
};