class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / GetGCD(p, q);

        return ((lcm / q) & 1) ? (((lcm / p) & 1) ? 1 : 0) : 2;
    }

private:
    int GetGCD(int a, int b) {
        int n;

        while (b) {
            n = a % b;
            a = b;
            b = n;
        }

        return a;
    }
};