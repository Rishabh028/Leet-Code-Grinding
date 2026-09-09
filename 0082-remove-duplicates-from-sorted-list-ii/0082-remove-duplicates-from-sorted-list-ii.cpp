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
        if  (!head || !head -> next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur && cur -> next) {
            if (cur -> val == cur -> next -> val) {
                while (cur -> next && cur -> val == cur -> next -> val) {
                    cur = cur -> next;
                }
                prev -> next = cur -> next;
            } else {
                prev = prev -> next;
            }
            cur = cur -> next;
        }
        return dummy -> next;
    }
};