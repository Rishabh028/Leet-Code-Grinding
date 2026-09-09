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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            int c = 1;
            ListNode* temp = curr;
            while (temp->next != NULL &&
                   temp->val == temp->next->val) {
                   c++;
                   temp = temp->next;
                }
                if (c == 1) {
                    prev = curr;
                    curr = curr->next;

                }else {
                    ListNode* after = temp->next;
                    ListNode* node = curr;
                    while (node != after) {
                        ListNode* next = node->next;
                        delete node;
                        node = next;
                    }
                    prev->next = after;
                    curr = after;
                }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};