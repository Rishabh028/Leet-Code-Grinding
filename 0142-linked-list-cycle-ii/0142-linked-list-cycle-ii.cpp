class Solution {
public:
    #define Node ListNode
    ListNode *detectCycle(ListNode *head) {
        Node *slow = head, *fast = head;
        while(slow and fast)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;   
            if(slow==fast) break;
        }
        if(!fast) return fast;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};