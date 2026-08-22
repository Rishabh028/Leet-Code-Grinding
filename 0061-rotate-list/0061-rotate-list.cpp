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
    ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int n = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    k = k % n;

    for (int i = 0; i < k; i++) {
        ListNode* itr = head;
        ListNode* prev = NULL;

        while (itr->next != NULL) {
            prev = itr;
            itr = itr->next;
        }

        itr->next = head;
        prev->next = NULL;
        head = itr;
    }

    return head;
}
};