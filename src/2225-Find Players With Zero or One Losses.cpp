class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> um;
        
        for (const vector<int>& match : matches) {
            if (!um.count(match[0]))
                um[match[0]] = 0;

            um[match[1]]++;
        }

        vector<vector<int>> ret(2, vector<int>());
        for (auto& p : um) {
            if (1 < p.second) continue;

            ret[p.second].push_back(p.first);
        }

        return ret;
    }
};