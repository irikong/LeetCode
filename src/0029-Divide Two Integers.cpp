class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == MIN ? -(dividend + 1) : -dividend;
        if (divisor == MIN) return divisor == dividend;
        if (dividend == MIN)
            return divisor & 1 ? divide(dividend + 1, divisor) : divide(dividend >> 1, divisor >> 1);

        int ret = 0;
        bool sign = !((0 <= dividend) ^ (0 <= divisor));

        if (dividend < 0) dividend = -dividend;
        if (divisor < 0) divisor = -divisor;

        while (divisor <= dividend) {
            int div = divisor, q = 1;

            while (div <= (MAX >> 1) && (div << 1) < dividend) {
                div <<= 1;
                q <<= 1;
            }

            dividend -= div;
            ret += q;
        }

        return sign ? ret : -ret;
    }

private:
    const int MIN = 1 << 31;
    const int MAX = -(MIN + 1);
};