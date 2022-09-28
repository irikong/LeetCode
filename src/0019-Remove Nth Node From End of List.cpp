/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;

        ListNode* curr = head;
        while (curr) {
            if (q.size() == n + 1) q.pop();
            q.push(curr);

            curr = curr->next;
        }

        if (q.size() == n) {
            curr = q.front(); q.pop();
            delete curr;

            head = q.empty() ? nullptr : q.front();
        }
        else {
			ListNode* prev = q.front(); q.pop();
			delete q.front(); q.pop();
			prev->next = q.empty() ? nullptr : q.front();
		}

        return head;
    }
};