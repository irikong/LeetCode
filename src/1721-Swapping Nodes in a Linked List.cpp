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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a = head;
        int size = 0;
        while (a) {
            a = a->next;
            size++;
        }

        int l = min(k, size + 1 - k);
        int r = max(k, size + 1 - k);

        a = head;
        for (int i = 1; i < l; i++)
            a = a->next;

        ListNode* b = a;
        for (int i = l; i < r; i++)
            b = b->next;

        swap(a->val, b->val);

        return head;
    }
};