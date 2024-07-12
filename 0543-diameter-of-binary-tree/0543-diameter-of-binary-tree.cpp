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
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int daim = 0;
        height(root, daim);
        return daim;
    }

private:
    int height(TreeNode* root, int& daim) {
        if (root == NULL)
            return 0;
        int lh = height(root->left, daim);
        int rh = height(root->right, daim);
        daim = max(daim, lh + rh);
        return 1 + max(lh, rh);
    }
};