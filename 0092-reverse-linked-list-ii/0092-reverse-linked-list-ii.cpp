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
        ListNode* copyHead = new ListNode(0);
        copyHead->next = head;
        ListNode* pre = copyHead;
        ListNode* nleft = copyHead->next;
        ListNode* nright = head; 
        for(int i = 0; i < left-1;i++){
            pre=nleft;
            nright = nright->next;
            nleft = nleft->next;
        }
        nright = nright->next;
        ListNode* curr = nleft;
        ListNode* prev = nullptr;
        ListNode* next; 
    
        for(int i = 0; i < right-left; i++){ 
            nright = nright->next;
        }
        while(curr!=nright){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        pre->next = prev;
        // copyHead->next = prev;
        nleft->next = nright;
        ListNode* res = copyHead->next;
        delete copyHead;
        return res;
    }
};