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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        
        ListNode dummy = { -201, head };
        ListNode* curr = head;
        ListNode* prev = &dummy;

        while (curr && curr->val < x) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* lessCurr = prev;
        ListNode* lessNext = curr;

        while (curr) {
            if (curr->val < x) {
                prev->next = curr->next;
                lessCurr->next = curr;
                lessCurr = curr;
            }
            else {
                prev = curr;
            }

			curr = curr->next;
        }
        lessCurr->next = lessNext;

        return dummy.next;
    }
};