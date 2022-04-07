class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        int big, small;
        while (1 < pq.size()) {
            big = pq.top(); pq.pop();
            small = pq.top(); pq.pop();

            if (big != small)
                pq.push(big - small);
        }

        return (pq.empty() ? 0 : pq.top());
    }
};