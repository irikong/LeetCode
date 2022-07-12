class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int l : matchsticks)
            sum += l;

        if (sum % 4)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sqLen(4, 0);

        return help(matchsticks, 0, sqLen, sum / 4);
    }

private:
    bool help(const vector<int>& matchsticks, int curr, vector<int>& sqLen, const int& maxLen) {
        if (curr == matchsticks.size()) {
            return (sqLen[0] == maxLen && sqLen[1] == maxLen && sqLen[2] == maxLen && sqLen[3] == maxLen);
        }
        
        for (int i = 0; i < 4; i++) {
            sqLen[i] += matchsticks[curr];

            if (sqLen[i] <= maxLen && help(matchsticks, curr + 1, sqLen, maxLen))
                return true;

            sqLen[i] -= matchsticks[curr];
        }

        return false;
    }
};