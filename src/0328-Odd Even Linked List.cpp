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
    ListNode* oddEvenList(ListNode* head) {
        if (head && head->next) {
			ListNode* prev = head;
			ListNode* curr = head->next;

			ListNode* evenHead = curr;
			bool isEven = true;
			while (curr->next) {
				prev->next = curr->next;

				prev = curr;
				curr = curr->next;
				isEven = !isEven;
			}

			if (isEven) {
				prev->next = evenHead;
				curr->next = nullptr;
			}
			else {
				prev->next = nullptr;
				curr->next = evenHead;
			}
        }

        return head;
    }
};