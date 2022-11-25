class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.size() - 1;
		int j = b.size() - 1;
        int carry = 0;

        while (0 <= i || 0 <= j || 0 < carry) {
            if (0 <= i) carry += a[i--] - '0';
            if (0 <= j) carry += b[j--] - '0';

            ret.push_back((carry % 2) + '0');
            carry >>= 1;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};