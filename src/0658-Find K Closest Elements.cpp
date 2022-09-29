class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pq;

        for (int num : arr) {
            pq.emplace(abs(num - x), num);
        }

        vector<int> ret;
        while (k--) {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        sort(ret.begin(), ret.end());

        return ret;
    }

    struct MyCompare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        }
    };
};