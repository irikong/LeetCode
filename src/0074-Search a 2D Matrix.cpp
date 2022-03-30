class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, r = row * col - 1, mid, midVal;

        while (l <= r) {
            mid = l + (r - l) / 2;
            midVal = matrix[mid / col][mid % col];

            if (midVal < target) {
                l = mid + 1;
            }
            else if (midVal > target) {
                r = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};