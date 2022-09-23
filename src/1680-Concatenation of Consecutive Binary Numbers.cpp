class Solution {
public:
    int concatenatedBinary(int n) {
        int modulo = 1e9 + 7;
        long long ret = 0;

        for (int i = 1; i <= n; i++) {
            int len = 0, num = i;
            while (num) {
                num >>= 1;
                len++;
            }

            ret = ((ret << len) + i) % modulo;
        }

        return ret;
    }
};