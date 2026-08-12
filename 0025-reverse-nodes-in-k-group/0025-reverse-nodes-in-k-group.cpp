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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* check=head;
        ListNode* nxt=nullptr;
        int cnt=0;
        while(check && cnt<k){
            check=check->next;
            cnt++;
        }
        if(cnt<k) return head;
        cnt=0;
        while(curr && cnt<k){
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;
             cnt++;
        }
        if(nxt){
            head->next=reverseKGroup(nxt,k);
        }
        return prev;
    }
};