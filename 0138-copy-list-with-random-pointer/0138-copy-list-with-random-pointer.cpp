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
        std::unordered_map<Node*, Node*> hashMap;
        Node* cur = head;

        while (cur) {
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        while (cur) {
            Node* copy = hashMap[cur];
            copy->next = hashMap[cur->next];
            copy->random = hashMap[cur->random];
            cur = cur->next;
        }

        return hashMap[head];        
    }
};