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
private:
    vector<int>ino(TreeNode* root){
        vector<int>post,pre,in;
        if(root==NULL) return post;
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            if(it.second==1){
                pre.push_back(it.first->val);
                st.push({it.first,2});
                if(it.first->left) st.push({it.first->left,1});
            }
            else if(it.second==2){
                in.push_back(it.first->val);
                st.push({it.first,3});
                if(it.first->right) st.push({it.first->right,1});
            }
            else{
                post.push_back(it.first->val);
            }
        }
        return in;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans=ino(root);
        return ans;
    }
};