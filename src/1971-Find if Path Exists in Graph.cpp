class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visit(n);

        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        visit[source] = true;
        DFS(graph, visit, source);

        return visit[destination];
    }

private:
    void DFS(vector<vector<int>>& graph, vector<bool>& visit, int curr) {
        for (int next : graph[curr]) {
            if (!visit[next]) {
                visit[next] = true;
                DFS(graph, visit, next);
            }
        }
    }
};