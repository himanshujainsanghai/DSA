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
    // bool isSorted(const std::vector<int>& vec) {
    //     for (size_t i = 0; i < vec.size() - 1; ++i) {
    //         if (vec[i] >= vec[i + 1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isvalid(TreeNode* root , long  minval , long maxval){
        if(root == NULL) return true;
        if(root->val <= minval || root->val >= maxval) return false;
        return( isvalid(root->left , minval , root->val) && isvalid(root->right , root->val , maxval));
    }
    

    bool isValidBST(TreeNode* root) {
        long long_min = std::numeric_limits<long>::min();
        long long_max = std::numeric_limits<long>::max();
        return isvalid(root , long_min , long_max);







        // vector<int> ans;
        // TreeNode* curr = root;
        // while (curr != NULL) {
        //     if (curr->left == NULL) {
        //         ans.push_back(curr->val);
        //         curr = curr->right;
        //     } else {
        //         TreeNode* prev = curr->left;
        //         while (prev->right && prev->right != curr) {
        //             prev = prev->right;
        //         }
        //         if (prev->right == NULL) {
        //             prev->right = curr;
        //             curr = curr->left;
        //         } else {
        //             prev->right = NULL;
        //             ans.push_back(curr->val);
        //             curr = curr->right;
        //         }
        //     }
        // }
        // if (isSorted(ans)) {
        //     return true;
        // }
        // return false;
    }
};