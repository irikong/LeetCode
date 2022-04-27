class Solution {
private:
    vector<vector<int>> adj;

    void BFS(const string& s, vector<int>& visit, const int root, vector<priority_queue<int, vector<int>, greater<int>>>& groupVec) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        queue<int> q;
        int groupNum = groupVec.size();

        q.push(root);
        visit[root] = groupNum;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            minHeap.push(s[curr]);

            for (int i = 0; i < adj[curr].size(); i++) {
                int next = adj[curr][i];

                if (visit[next] == -1) {
                    q.push(next);
                    visit[next] = groupNum;
                }
            }
        }

        groupVec.push_back(minHeap);
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> visit(s.size(), -1);
        vector<priority_queue<int, vector<int>, greater<int>>> groupVec;
        adj = vector<vector<int>>(s.size(), vector<int>());
        for (const vector<int>& p : pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < s.size(); i++) {
            if (visit[i] == -1) {
                BFS(s, visit, i, groupVec);
            }
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = groupVec[visit[i]].top();
            groupVec[visit[i]].pop();
        }

        return s;
    }
};