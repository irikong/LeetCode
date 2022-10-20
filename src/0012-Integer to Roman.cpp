class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";

        for (int i = 1; i < 1000; i *= 10) {
            m[4 * i] = m[1 * i] + m[5 * i];
            m[9 * i] = m[1 * i] + m[10 * i];
        }

        string ret;
        while (num) {
            for (auto item : m) {
                if (num >= item.first) {
                    num -= item.first;
                    ret.append(item.second);
                    break;
                }
            }
        }

        return ret;
    }
};