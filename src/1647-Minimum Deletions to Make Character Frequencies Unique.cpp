class Solution {
public:
	int minDeletions(string s) {
		array<int, 26> arr = { 0, };
		int ret = 0;

		for (const char& c : s)
			arr[c - 'a']++;

		sort(arr.begin(), arr.end(), greater<int>());

		for (int i = 1; i < arr.size(); i++) {
			if (arr[i] == 0) break;
			else if (arr[i - 1] == 0) {
				ret += arr[i];
				arr[i] = 0;
			}
			else if (arr[i] >= arr[i - 1]) {
				int temp = arr[i] - arr[i - 1] + 1;
				arr[i] -= temp;
				ret += temp;
			}
		}

		return ret;
	}
};