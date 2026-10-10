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
    int lefh(TreeNode* root){
        int c=0;
        while(root!=NULL){
            c++;
            root=root->left;
        }
        return c;
    }
    int righ(TreeNode* root){
        int c=0;
        while(root!=NULL){
            c++;
            root=root->right;
        }
        return c;
    }

    int help(TreeNode* root){
        if(root==NULL) return 0;
        int lef=lefh(root);
        int rig=righ(root);
        if(lef==rig){
            return (1<<lef)-1;   
        }
        return 1+help(root->left)+help(root->right);
    }


    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return help(root);
    }
};