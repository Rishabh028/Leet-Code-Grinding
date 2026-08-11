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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* pre = NULL;

        while(first != NULL && second != NULL){
            
            ListNode* th = second->next;
            second->next = first;
            first->next = th;

            if(pre != NULL){
                pre->next = second;
            }else{
                head = second;
            }

            pre = first;
            first = th;
            

            if(th != NULL){
                second = th->next;

            }else{
                second = NULL;
            }
        }

        return head;

    }

};