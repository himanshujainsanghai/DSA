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


// level order traversal 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        map<int , int> mpp;
        queue<pair<TreeNode* , int>> que;
        que.push({root , 0});
        while(!que.empty()){
            auto it = que.front();
            que.pop();
            TreeNode* node = it.first;
            int ind = it.second;
            mpp[ind]= node->val;
            if(node->left != NULL) que.push({node->left , ind+1});
            if(node->right != NULL) que.push({node->right ,ind+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};