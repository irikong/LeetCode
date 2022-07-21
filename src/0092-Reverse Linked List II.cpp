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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        stack<ListNode*> st;
        int cnt = 1;

        while (cnt < left) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        while (cnt <= right) {
            st.push(curr);
            curr = curr->next;
            cnt++;
        }

        if (prev) prev->next = st.top();
        else head = st.top();
        while (!st.empty()) {
            prev = st.top();
            st.pop();
            prev->next = st.empty() ? curr : st.top();
        }

        return head;
    }
};