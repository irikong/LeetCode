class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0, N = costs.size() >> 1, aCnt = 0, bCnt = 0;
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (abs(a[0] - a[1]) > abs(b[0] - b[1]));
            });

        for (const vector<int>& cost : costs) {
            if (N == aCnt) {
                ret += cost[1];
                bCnt++;
            }
            else if (N == bCnt) {
                ret += cost[0];
                aCnt++;
            }
            else {
                ret += cost[cost[0] > cost[1]];
                cost[0] < cost[1] ? aCnt++ : bCnt++;
            }

        }

        return ret;
    }
};