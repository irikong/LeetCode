class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ret = 0;
        sort(people.begin(), people.end());
        int si = 0, bi = people.size() - 1;

        while (si <= bi) {
            if (people[bi] + people[si] <= limit) {
                si++;
            }

            bi--;
            ret++;
        }

        return ret;
    }
};