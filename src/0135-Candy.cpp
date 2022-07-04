class Solution {
public:
    int candy(vector<int>& ratings) {
        int curr = 1, n = ratings.size(), ret = 0;
        vector<int> arr(n, 0);
        arr[0] = 1;

        while (curr < n) {
            if (ratings[curr] > ratings[curr - 1]) {
                arr[curr] = arr[curr - 1] + 1;
                curr++;
            }
            else if (ratings[curr] < ratings[curr - 1]) {
                int minIdx = curr;
                while (minIdx + 1 < n && ratings[minIdx] > ratings[minIdx + 1]) minIdx++;

                int c = minIdx - curr + 1;
                for (int i = curr; i <= minIdx; i++)
                    arr[i] = c--;

                arr[curr - 1] = max(arr[curr - 1], arr[curr] + 1);
                curr = minIdx + 1;
            }
            else {
                arr[curr++] = 1;
            }
        }

        for (int& c : arr) {
            ret += c;
        }

        return ret;
    }
};