/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* imp(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = imp(root->left, p, q);
        TreeNode* right = imp(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) {
            return root;
        }
        return imp(root, p, q);
    }
};