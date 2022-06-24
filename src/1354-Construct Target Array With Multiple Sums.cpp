class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        
        priority_queue<int> pq;
        long long sum = 0;

        for (const int num : target) {
            pq.push(num);
            sum += num;
        }

        while (pq.top() != 1) {
            long long next = 2 * pq.top() - sum;
            long long otherSum = sum - pq.top();
            if (pq.size() + pq.top() - 1 == sum) {
                return !((sum - 1) % otherSum);
            }

            next %= otherSum;
            if (next < 1) return false;
            
            sum = otherSum + next;
            pq.push(next);
            pq.pop();
        }

        return true;
    }
};