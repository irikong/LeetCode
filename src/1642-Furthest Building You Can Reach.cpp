class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        int currH = heights[0];
        int brickSum = 0, next;

        for (next = 1; next < heights.size(); next++) {
            int nextH = heights[next];

            if (currH < nextH) {
				pq.push(nextH - currH);
                brickSum += nextH - currH;

                if (brickSum > bricks) {
                    if (ladders) {
                        ladders--;

                        brickSum -= pq.top();
                        pq.pop();
                    }
                    else break;
                }
            }

            currH = nextH;
        }

        return next - 1;
    }
};