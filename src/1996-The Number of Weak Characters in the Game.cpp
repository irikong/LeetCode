class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end());
		int ret = 0;

		vector<int> atkEnds;
		int prevAtk = properties[0][0];
		for (int i = 1; i < properties.size(); i++) {
			if (properties[i][0] != prevAtk) {
				atkEnds.push_back(i - 1);
				prevAtk = properties[i][0];
			}
		}
		atkEnds.push_back(properties.size() - 1);

		vector<int> maxDefs(atkEnds.size(), 0);
		int maxDef = -1;
		for (int i = atkEnds.size() - 1; i > 0; i--) {
			maxDef = max(maxDef, properties[atkEnds[i]][1]);
			maxDefs[i - 1] = maxDef;
		}

		int loopEnd = atkEnds.size() - 1;
		for (int i = 0; i < loopEnd; i++) {
			int atkBegin = i ? atkEnds[i - 1] + 1 : 0;
			int atkEnd = atkEnds[i];

			for (int j = atkBegin; j <= atkEnd; j++) {
				if (properties[j][1] < maxDefs[i]) ret++;
				else break;
			}
		}

		return ret;
	}
};