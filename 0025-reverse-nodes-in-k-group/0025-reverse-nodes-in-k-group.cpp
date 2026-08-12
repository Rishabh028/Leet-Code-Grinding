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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode start(0, head);
        ListNode* ret = &start;

        ListNode* prev = ret;
        ListNode* tail = head;

        while(true) {
            for(int i=0; i<k; i++) {
                if(!tail) return ret->next;
                tail = tail->next;
            }

            ListNode* now = prev->next;

            for(int i=0; i<k-1; i++) {
                ListNode* temp = now->next;
                now->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }

            prev = now;
            tail = prev->next;
        }
    }
};