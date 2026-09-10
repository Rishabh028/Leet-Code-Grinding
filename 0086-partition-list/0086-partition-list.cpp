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
    ListNode* partition(ListNode* head, int x) {
        ListNode* right = new ListNode(0);
        ListNode* aux = head;
        ListNode* left = right;
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        while(aux->next != nullptr && aux->val >= x) {
            right->next = new ListNode(aux->val);
            right = right->next;
            aux = aux->next;
        }
        if(aux->val >= x)return head;
        head = aux;
        while(aux != nullptr && aux-> next != nullptr) {
            if(aux->next->val < x) {
                aux = aux->next;
            }else{
                right->next = new ListNode(aux->next->val);
                right = right->next;
                aux-> next = aux->next->next;
            }
        }
        aux->next = left->next;
        return head;
    }
};