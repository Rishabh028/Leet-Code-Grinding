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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root, int binary = 0) {
        if(root == NULL)return 0;
        binary <<=1;
        binary |= (root->val);
        if(root->left == NULL && root->right == NULL){
            sum += binary;
            return sum;
        }
        sumRootToLeaf(root->left,binary);
        sumRootToLeaf(root->right,binary);
        return sum;
    }
};