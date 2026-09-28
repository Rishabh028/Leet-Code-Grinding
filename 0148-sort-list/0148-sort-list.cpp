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
        vector<int> vec;
        ListNode *temp = head;
        while (temp != NULL) {
            vec.push_back(temp -> val);
            temp = temp -> next;
        }
        sort(vec.begin(), vec.end());
        temp = head;
        int idx = 0;
        while(temp != NULL) {
            temp -> val = vec[idx++];
            temp = temp -> next;
        }
        return head;
    }
};