class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        for (int num : arr) {
            um[num]++;
        }

        unordered_set<int> us;
        for (auto& iter : um) {
            if (us.count(iter.second)) return false;
            
            us.insert(iter.second);
        }

        return true;
    }
};