class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ret;
        queue<int> q;

        sort(changed.begin(), changed.end());

        for (int num : changed) {
            if (q.empty() || q.front() * 2 != num) {
                q.push(num);
            }
            else {
                ret.push_back(q.front());
                q.pop();
            }
        }
        
        if (!q.empty()) ret.clear();

        return ret;
    }
};