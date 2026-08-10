class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using P = pair<long,ListNode*>;
        priority_queue<P, vector<P>, greater<P>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
            pq.push({(long)lists[i]->val,lists[i]});
        }
        ListNode *head=new ListNode();
        ListNode *cur=head;
        while(!pq.empty()){
            pair<long,ListNode*>u=pq.top();pq.pop();
            cur->next=u.second;
            u.second=u.second->next;
            if(u.second!=nullptr){
                pq.push({u.second->val,u.second});
            }
            cur=cur->next;
        }
        return head->next;
    }
};