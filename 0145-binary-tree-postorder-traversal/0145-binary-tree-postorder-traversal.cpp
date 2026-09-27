class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        if (root == nullptr)
            return ans;

        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            if (curr->left)
                st.push(curr->left);

            if (curr->right)
                st.push(curr->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};