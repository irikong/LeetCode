class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for (string& word : words) {
            um[word]++;
        }

        vector<pair<string, int>> siVec(um.begin(), um.end());
        sort(siVec.begin(), siVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });

        vector<string> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(siVec[i].first);
        }

        return ret;
    }
};