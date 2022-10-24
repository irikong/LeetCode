class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ret = 0;

        set<char> charSet;
        for (int i = 0; i < arr.size(); i++) {
            Helper(arr, charSet, i, ret);
        }

        return ret;
    }

private:
    void Helper(const vector<string>& arr, set<char> charSet, int curr, int& out) {
        for (char c : arr[curr]) {
            if (charSet.count(c) == 0)
                charSet.insert(c);
            else
                return;
        }

        out = max(out, static_cast<int>(charSet.size()));
        if (out == 26) return;

        for (int i = curr + 1; i < arr.size(); i++) {
            if (charSet.size() + arr[i].size() <= 26)
                Helper(arr, charSet, i, out);
        }
    }
};