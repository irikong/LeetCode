class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26];
        memset(alpha, 0x3f3f3f3f, 26 * sizeof(int));

        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            
            if (alpha[a] == 0x3f3f3f3f) {
                alpha[a] = i;
            }
            else {
                alpha[a] = -1;
            }
        }

        int ret = 0x3f3f3f3f;
        for (int idx : alpha) {
            if (idx == -1) continue;
            
            ret = min(ret, idx);
        }

        return (ret == 0x3f3f3f3f ? -1 : ret);
    }
};