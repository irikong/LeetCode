class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int> v2) {
			return v1[1] < v2[1];
		});

		priority_queue<int> pq;
		int durationSum = 0;

		for (const vector<int>& c : courses) {
			if (durationSum + c[0] <= c[1]) {
				pq.push(c[0]);
				durationSum += c[0];
			}
			else if (!pq.empty() && c[0] < pq.top()) {
				durationSum -= pq.top();
				pq.pop();

				durationSum += c[0];
				pq.push(c[0]);
			}
		}

		return pq.size();
	}
};