class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> anagramMap;

        for (const string& s : strs) {
            string sorted(s);
            sort(sorted.begin(), sorted.end());
            anagramMap[sorted].push_back(s);
        }

        for (auto& p : anagramMap) {
            ret.push_back(move(p.second));
        }

        return ret;
    }
};