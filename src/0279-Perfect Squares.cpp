class Solution {
public:
    int numSquares(int n) {
        int ret = 0;
        vector<int> squares(101);
        for (int i = 1; i <= 100; i++) {
            squares[i] = i * i;
        }

        unordered_set<int> us;
        queue<int> q;
        q.push(n);

        while (!q.empty()) {
            int qSize = q.size();

            while (qSize--) {
                int curr = q.front();
                q.pop();

                for (int i = 1; i * i <= curr; i++) {
                    int temp = curr - squares[i];

                    if (temp == 0) return ret + 1;
                    else if (us.count(temp) == 0) {
                        us.insert(temp);
                        q.push(temp);
                    }
                }
            }

            ret++;
        }

        return n;
    }
};