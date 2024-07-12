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
    int maxsum = INT_MIN;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftsum = max( height(root->left) , 0);
        int rightsum = max(height(root->right) , 0);
        maxsum = max(maxsum, leftsum + rightsum + root->val);

        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        height(root);
        return maxsum;
    }
};