class Solution {
public:
	using pii = pair<int, int>;

    bool isPossible(vector<int>& nums) {
        unordered_map<int, vector<int>> um;

        for (int num : nums) {
            if (!um.count(num)) um[num] = vector<int>(4, 0);

            if (!um.count(num - 1)) {
                um[num][1]++;
            }
            else {
                bool find = false;
                int i = 0;

                while (i < 4) {
                    if (um[num - 1][i]) {
                        um[num - 1][i]--;
                        um[num][min(i + 1, 3)]++;
                        find = true;
                        break;
                    }

                    i++;
                }

                if (!find) um[num][1]++;
            }
        }

        for (const auto& iv : um) {
            for (int i = 0; i < 3; i++) {
                if (iv.second[i]) return false;
            }
        }

        return true;
    }
};