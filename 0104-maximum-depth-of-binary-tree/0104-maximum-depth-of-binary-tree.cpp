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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh =0 , rh =0;    

        if (root->left != NULL) {
            lh = maxDepth(root->left);

        }
        if (root->right != NULL) {

            rh = maxDepth(root->right);
        }

        return 1 + max(lh, rh);
    }
};

// class Solution {
// public:
//     void solve(TreeNode* root, int height, int& maxheight) {
//         if (root == nullptr)
//             return;
//         if (root->right == nullptr && root->left == nullptr) {
//             maxheight = max(maxheight, height);
//         }
//         solve(root->left, height + 1, maxheight);
//         solve(root->right, height + 1, maxheight);
//     }

// public:
//     int maxDepth(TreeNode* root) {
//         if (root == nullptr)
//             return 0;
//         int height = 1;
//         int maxheight = 0;
//         solve(root, height, maxheight);
//         return maxheight;
//     }
// };