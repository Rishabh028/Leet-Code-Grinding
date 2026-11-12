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
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Create dummy nodes for odd and even lists
        ListNode oddDummy(0);
        ListNode evenDummy(0);

        ListNode* odd = &oddDummy;
        ListNode* even = &evenDummy;

        ListNode* temp = head;
        int pos = 1;

        while (temp != NULL) {

            ListNode* nextNode = temp->next;

            if (pos % 2 == 1) {
                odd->next = temp;
                odd = odd->next;
            }
            else {
                even->next = temp;
                even = even->next;
            }

            temp = nextNode;
            pos++;
        }

        even->next = NULL;

        odd->next = evenDummy.next;

        return oddDummy.next;
    }
};