class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPower = pow(3, 19);

        return !(maxPower % n);
    }
};