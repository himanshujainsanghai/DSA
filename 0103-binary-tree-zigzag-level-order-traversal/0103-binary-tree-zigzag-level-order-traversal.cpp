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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool LeftToRight = true;
        while(!que.empty()){
            int size = que.size();
            vector<int> row(size);
            for(int i =0 ; i<size ; i++){
                TreeNode* node = que.front();
                que.pop();

                int index = (LeftToRight)? i:size-i-1;
                row[index] = node->val;
                if(node->left){
                    que.push(node->left);

                }
                if(node->right){
                    que.push(node->right);
                }
            }
            LeftToRight = !LeftToRight;
            ans.push_back(row);
        }
        return ans;
        
    }
};