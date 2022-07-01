class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[1] > b[1];
		});

		int ret = 0;

		for (const vector<int>& box : boxTypes) {
			if (truckSize >= box[0]) {
				truckSize -= box[0];
				ret += box[0] * box[1];
			}
			else {
				ret += truckSize * box[1];
				break;
			}
		}

		return ret;
	}
};