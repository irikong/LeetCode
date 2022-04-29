class Solution {
private:
	bool BFS(const vector<vector<int>>& graph, vector<int>& visit, int start) {
		queue<int> q;

		visit[start] = 0;
		q.push(start);

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int next : graph[curr]) {
				if (visit[next] == -1) {
					visit[next] = !visit[curr];
					q.push(next);
				}
				else if (visit[next] == visit[curr]) {
					return false;
				}
			}
		}

		return true;
	}

public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> visit(graph.size(), -1);

		for (int i = 0; i < visit.size(); i++) {
			if (visit[i] == -1 && !BFS(graph, visit, i))
				return false;
		}

		return true;
	}
};