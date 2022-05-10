class Solution {
private:
    void Solve(vector<vector<int>>& ret, const int k, const int n, vector<int>& comb, int sum) {
        if (comb.size() == k) {
            if (sum == n) ret.push_back(comb);
            return;
        }
        else if (n <= sum) return;

        int b = comb.back() + 1;
        int e = 10 - (k - comb.size());
        for (int i = b; i <= e; i++) {
            comb.push_back(i);
            Solve(ret, k, n, comb, sum + i);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> comb;

        int e = 10 - k;
        for (int i = 1; i <= e; i++) {
            comb.push_back(i);
            Solve(ret, k, n, comb, i);
            comb.pop_back();
        }

        return ret;
    }
};