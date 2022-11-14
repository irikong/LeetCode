class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int unionNum = 0;
        vector<bool> visit(stones.size(), false);

        for (int i = 0; i < visit.size(); i++) {
            if (!visit[i]) {
                unionNum++;
                DFS(stones, visit, i);
            }
        }

        return stones.size() - unionNum;
    }

private:
    void DFS(vector<vector<int>>& stones, vector<bool>& visit, int curr) {
        visit[curr] = true;

        for (int i = 0; i < stones.size(); i++) {
            if (!visit[i] && ((stones[i][0] == stones[curr][0]) || (stones[i][1] == stones[curr][1]))) {
                DFS(stones, visit, i);
            }
        }
    }
};