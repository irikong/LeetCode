class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ret = 0;
        vector<bool> visit(bank.size(), false);
        queue<string> q;
        q.push(start);

        string curr;
        while (!q.empty()) {
            int qSize = q.size();
            ret++;

            while (qSize--) {
                curr = q.front();
                q.pop();

                for (int i = 0; i < bank.size(); i++) {
                    if (!visit[i] && isValid(curr, bank[i])) {
                        if (bank[i] == end) return ret;

                        q.push(bank[i]);
                        visit[i] = true;
                    }
                }
            }
        }

        return -1;
    }

private:
    bool isValid(const string& a, const string& b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i] && ++diff > 1)
                return false;
        }

        return true;
    }
};