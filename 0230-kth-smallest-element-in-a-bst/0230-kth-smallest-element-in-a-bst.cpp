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
int kSmallest = 0;
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        inorder(root , counter , k , kSmallest);
        return kSmallest;

        // vector<int> ans;
        // TreeNode* curr = root;
        // while(curr != NULL){
        //     if(curr->left == NULL){
        //         ans.push_back(curr->val);
        //         curr = curr->right;
        //     }
        //     else{
        //         TreeNode* prev = curr->left;
        //         while(prev->right && prev->right != curr){
        //             prev = prev->right;
        //         }
        //         if(prev->right == NULL){
        //             prev->right = curr;
        //             curr = curr->left;
        //         }
        //         else{
        //             prev->right = NULL;
        //             ans.push_back(curr->val);
        //             curr= curr->right;

        //         }
        //     }
        // }
        // return ans[k-1];


        
    }
};