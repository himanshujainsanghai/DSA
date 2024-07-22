/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* findLastRight(TreeNode* root) {
        // if (root->right == NULL)
        //     return root;
        // return findLastRight(root->right);
        while(root->right != NULL) root = root->right;
        return root;
    }
    TreeNode* mainconfig(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            TreeNode* rightChild = root->right;
            TreeNode* lastt = findLastRight(root->left);
            lastt->right = rightChild;
            return root->left;
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return mainconfig(root);
        TreeNode* node = root;
        while (node != NULL) {
            if (key > node->val) {
                if (node->right != NULL && node->right->val == key) {
                    node->right = mainconfig(node->right);
                    // break;
                } else
                    node = node->right;
            } else {
                if (node->left != NULL && node->left->val == key) {
                    node->left = mainconfig(node->left);
                    // break;
                } else
                    node = node->left;
            }
        }
        return root;
    }
};