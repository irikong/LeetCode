class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int r = 0; r < rSize; r++) {
            for (int c = 0; c < cSize; c++) {
                minHeap.push(matrix[r][c]);
            }
        }

        int ret;
        while (k--) {
            ret = minHeap.top();
            minHeap.pop();
        }

        return ret;
    }
};