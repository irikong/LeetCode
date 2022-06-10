class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        unordered_set<char> us;
        queue<char> q;

        for (const char& c : s) {
            if (us.count(c)) {
                while (q.front() != c) {
                    us.erase(q.front());
                    q.pop();
                }

                q.pop();
                q.push(c);
            }
            else {
                us.insert(c);
                q.push(c);

                if (ret < q.size())
                    ret = q.size();
            }
        }

        return ret;
    }
};