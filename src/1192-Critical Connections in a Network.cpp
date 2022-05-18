class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		graph = vector<vector<int>>(n);
		visitTime = vector<int>(n, 0);
		minTime = vector<int>(n);

		for (const vector<int>& edge : connections) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		DFS(0, -1);

		return ret;
	}

private:
	vector<vector<int>> ret;
	vector<vector<int>> graph;
	vector<int> visitTime, minTime;
	int time = 1;

	void DFS(int curr, int prev) {
		visitTime[curr] = minTime[curr] = time++;

		for (int& next : graph[curr]) {
			if (next == prev) continue;

			if (!visitTime[next]) DFS(next, curr);

			minTime[curr] = min(minTime[curr], minTime[next]);

			if (visitTime[curr] < minTime[next])
				ret.push_back({ curr, next });
		}
	}
};