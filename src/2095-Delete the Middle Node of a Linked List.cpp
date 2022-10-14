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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fast = head->next;
        
        while (fast) {
            prev = curr;
            curr = curr->next;
            fast = fast->next ? fast->next->next : nullptr;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};