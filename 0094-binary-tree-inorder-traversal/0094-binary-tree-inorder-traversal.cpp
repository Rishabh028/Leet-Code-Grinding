/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* n = root;
        while(st.size()> 0 || n){
            if(n != NULL) {
                st.push(n);
                n = n -> left;
            }
            else {
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp -> val);
                n = temp -> right;
            }
        }
        return ans;
    }
};