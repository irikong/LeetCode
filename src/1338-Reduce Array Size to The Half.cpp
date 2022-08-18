class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> um;
        priority_queue<pair<int, int>> pq;

        for (int num : arr)
            um[num]++;

        for (const auto& item : um)
            pq.push({ item.second, item.first });

        int ret = 0;
        int curr = arr.size(), half = arr.size() / 2;
        while (curr > half) {
            ret++;
            curr -= pq.top().first;
            pq.pop();
        }

        return ret;
    }
};