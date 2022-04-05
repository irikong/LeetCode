class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int area = min(height[lp], height[rp]) * (rp - lp);

        while (lp < rp) {
            if (height[lp] < height[rp]) {
                int nlp = lp;
                while (nlp < rp && height[nlp] <= height[lp]) nlp++;
                lp = nlp;
            }
            else if (height[lp] > height[rp]) {
                int nrp = rp;
                while (nrp > lp && height[nrp] <= height[rp]) nrp--;
                rp = nrp;
            }
            else {
                int np = lp;
                while (np < rp && height[np] <= height[lp]) np++;
                lp = np;

                np = rp;
                while (np > lp && height[np] <= height[rp]) np--;
                rp = np;
            }

            int nArea = min(height[lp], height[rp]) * (rp - lp);
            if (area < nArea) area = nArea;
        }

        return area;
    }
};