/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node  * temp1 = head;
       Node * dummy = new Node(-1);
       Node * temp2= dummy;
       vector<Node*> index;
       unordered_map <Node*,int> store;
       int i=0;
        while(temp1!=nullptr){
            int val=temp1->val;
            temp2->next= new Node (val);
             
            temp2=temp2->next;
            index.push_back(temp2);
            store.insert({temp1,i});
            i++;
            temp1=temp1->next;
        }
        temp1=head;
        temp2=dummy->next;
        while(temp1!=nullptr){
            int val=store[temp1->random];
            if(temp1->random==nullptr){
                temp2->random=nullptr;
            }else{
            temp2->random=index[val];}
            
            temp2=temp2->next;
            temp1=temp1->next;
        }
        return dummy->next ;
    }
};