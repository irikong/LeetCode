class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < s.size(); i++) {
            if (!m.count(s[i])) m[s[i]].first = i;
            m[s[i]].second = i;
        }

        vector<pair<int, int>> mVec;
        for (const auto& elem : m) {
            mVec.emplace_back(elem.second);
        }
        sort(mVec.begin(), mVec.end());

        int start = 0, end = 0;
        for (const auto& value : mVec) {
            if (value.first <= end) {
                end = max(end, value.second);
            }
            else {
                ans.push_back(end - start + 1);

                start = value.first;
                end = value.second;
            }
        }
        ans.push_back(end - start + 1);

        return ans;
    }
};