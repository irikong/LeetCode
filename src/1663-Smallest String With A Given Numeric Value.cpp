class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;

        int temp;
        while (k) {
            temp = min(k, 25);
            ans[--n] += temp;
            k -= temp;
        }

        return ans;
    }
};