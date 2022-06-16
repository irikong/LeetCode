class Solution {
public:
    string longestPalindrome(string s) {
        queue<pair<int, int>> q;
        int last = s.size() - 1;

        for (int i = 0; i < last; i++) {
            if (s[i] == s[i + 1]) q.push({ i, i + 1 });
            if (i + 2 <= last && s[i] == s[i + 2]) q.push({ i, i + 2 });
        }
        
        pair<int, int> longest = q.empty() ? make_pair(0, 0) : q.front();
        pair<int, int> curr;
        int diff = longest.second - longest.first;
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            if (curr.first != 0 && curr.second != last && s[curr.first - 1] == s[curr.second + 1]) {
                curr.first--;
                curr.second++;
                q.push(curr);
            }
            else if (diff < curr.second - curr.first) {
                longest = curr;
                diff = longest.second - longest.first;
            }
        }

        return s.substr(longest.first, diff + 1);
    }
};