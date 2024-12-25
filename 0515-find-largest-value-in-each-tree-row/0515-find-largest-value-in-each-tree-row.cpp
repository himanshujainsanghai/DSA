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
    vector<int> largestValues(TreeNode* root) {
        if(root== nullptr){
            return {};
        }
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;
        while(!que.empty()){
            int  n = que.size();
            int maxi = INT_MIN;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                maxi = max(maxi , node->val);
                if(node->left != NULL){
                    que.push(node->left);
                }
                if(node->right != NULL){
                    que.push(node->right);
                }

            }

            ans.push_back(maxi);
            
        }

        return ans;
        
    }
};