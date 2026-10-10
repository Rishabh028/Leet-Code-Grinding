
class Solution {
public:

    int leftHeight(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->left;
        }

        return h;
    }

    int rightHeight(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};