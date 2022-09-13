class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int stack = 0;
        for (int num : data) {
            if (stack) {
                if (GetZeroIdx(num) != 1) return false;
                stack--;
            }
            else {
                int temp = GetZeroIdx(num);
                if (temp == 0)
                    continue;
                else if (2 <= temp)
                    stack = temp - 1;
                else
                    return false;
            }
        }

        return stack == 0;
    }

private:
    int GetZeroIdx(int num) {
        int temp = 1 << 7;

        for (int i = 0; i < 5; i++) {
            if (!(num & temp)) return i;
            temp >>= 1;
        }

        return -1;
    }
};