class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vCnt(5, 0);
        int ret = 0;

        vCnt[0] = 1;
        while (--n) {
            for (int i = 1; i < 5; i++) {
                vCnt[i] += vCnt[i - 1];
            }
        }

        for (int i = 0; i < 5; i++) {
            ret += (5 - i) * vCnt[i];
        }

        return ret;
    }
};