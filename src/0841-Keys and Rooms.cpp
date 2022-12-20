class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int N = rooms.size();
        unordered_set<int> visit;
        queue<int> q;

        q.push(0);
        visit.insert(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int key : rooms[curr]) {
                if (!visit.count(key)) {
                    q.push(key);
                    visit.insert(key);
                }
            }
        }

        return visit.size() == N;
    }
};