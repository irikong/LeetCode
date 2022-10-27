class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = img1.size(), M = 3 * N - 2;
        vector<vector<int>> expand(M, vector<int>(M, 0));

        int offset = N - 1;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                expand[r + offset][c + offset] = img1[r][c];
            }
        }

        int last = M - offset, ret = 0;
        for (int expR = 0; expR < last; expR++) {
            for (int expC = 0; expC < last; expC++) {
                int overlap = 0;

                for (int r = 0; r < N; r++) {
                    for (int c = 0; c < N; c++) {
                        overlap += img2[r][c] & expand[expR + r][expC + c];
                    }
                }

                ret = max(ret, overlap);
            }
        }

        return ret;
    }
};