class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret = 0, num = target;

        while (startValue < num) {
            if (num & 1)
                num++;
            else
                num >>= 1;

            ret++;
        }

        if (num < startValue)
            ret += startValue - num;

        return ret;
    }
};