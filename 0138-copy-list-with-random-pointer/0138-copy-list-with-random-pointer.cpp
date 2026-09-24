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
    map<Node*, Node > mp;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* node = head;
        while (node) {
                mp[node] = new Node(node->val);
                node = node -> next;
            }
            node = head;
            Node* temp = nullptr;
            while (node) {
                temp = mp[node];
                temp -> next = mp[node -> next];
                temp -> random = mp[node -> random];
                node = node -> next;
            }
            return mp[head];
    }
};