class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPower = pow(3, 19);

        return (0 < n) && !(maxPower % n);
    }
};