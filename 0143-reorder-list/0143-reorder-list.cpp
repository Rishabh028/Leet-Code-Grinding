class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int>n;
        int i=0,c=0,j,m;
        ListNode* ptr=head;

        while(ptr!=nullptr)
        {
            n.push_back(ptr->val);
            ptr=ptr->next;
            c++;
        }
        j=c;
        m=c;
        c=0;
        ptr=head;

        while(c<j)
        {
            if(c%2==0)
            ptr->val=n[i++];
            else
            ptr->val=n[m-i];
            c++;
            ptr=ptr->next;
        }

    }
};