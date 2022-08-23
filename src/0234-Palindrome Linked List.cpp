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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        queue<int> q;
        stack<int> st;

        while (curr) {
            q.push(curr->val);
            st.push(curr->val);
            curr = curr->next;
        }

        int halfLen = q.size() / 2;
        while (halfLen--) {
            if (q.front() != st.top()) return false;
            q.pop();
            st.pop();
        }

        return true;
    }
};