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
class compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for (ListNode* listhead:lists){
            if (listhead) pq.push(listhead);
        }
        while (!pq.empty()){
            ListNode* currNode=pq.top();
            pq.pop();
            tail->next=currNode;
            tail=tail->next;
            if (currNode->next)     pq.push(currNode->next);
        }
        return head->next;
    }
};