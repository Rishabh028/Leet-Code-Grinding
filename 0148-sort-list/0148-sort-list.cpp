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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> res;
        if (head == NULL or head -> next == NULL) return head;
        int i = 0;
        while (temp != NULL) {
            res.push_back(temp -> val);
            temp = temp -> next;
            i++;
        }
        i = 0;
        sort (res.begin(), res.end());
        temp = head;
        while (temp != NULL) {
            temp -> val = res[i];
            temp = temp -> next;
            i++;
        }
        return head;
    }
};