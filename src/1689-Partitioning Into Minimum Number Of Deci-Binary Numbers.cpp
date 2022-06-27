class Solution {
public:
    int minPartitions(string n) {
        int cNum = 0;

        for (const char& c : n) {
            if (cNum < c) {
                cNum = c;

                if (cNum == '9') break;
            }
        }

        return cNum - '0';
    }
};