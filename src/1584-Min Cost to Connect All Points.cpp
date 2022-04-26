class Solution {
private:
    int GetManhattanDist(const vector<int>& p1, const vector<int>& p2) {
        return abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size(), ret = 0;
        vector<bool> visit(N, false);
        vector<vector<int>> graph(N, vector<int>(N, 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int dist = GetManhattanDist(points[i], points[j]);
                graph[i][j] = graph[j][i] = dist;
            }
        }

        visit[0] = true;
        for (int next = 1; next < N; next++) {
            minHeap.push({ graph[0][next], next });
        }

        int curr, currCost;
        while (!minHeap.empty()) {
            curr = minHeap.top().second;
            currCost = minHeap.top().first;
            minHeap.pop();

            if (visit[curr]) continue;

            visit[curr] = true;
            ret += currCost;

            for (int next = 0; next < N; next++) {
                if (!visit[next])
                    minHeap.push({ graph[curr][next], next });
            }
        }

        return ret;
    }
};