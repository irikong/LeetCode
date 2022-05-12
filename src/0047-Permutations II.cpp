class Solution {
private:
    void Solve(const vector<int>& nums, set<vector<int>>& permuteSet, vector<int>& permuteVec, vector<bool>& visit) {
        if (permuteVec.size() == nums.size()) {
            permuteSet.insert(permuteVec);
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!visit[i]) {
                    visit[i] = true;
                    permuteVec.push_back(nums[i]);
                    Solve(nums, permuteSet, permuteVec, visit);
                    permuteVec.pop_back();
                    visit[i] = false;
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> permuteSet;
        vector<int> permuteVec;
        vector<bool> visit(nums.size(), false);

        Solve(nums, permuteSet, permuteVec, visit);
        ret = vector<vector<int>>(permuteSet.begin(), permuteSet.end());

        return ret;
    }
};