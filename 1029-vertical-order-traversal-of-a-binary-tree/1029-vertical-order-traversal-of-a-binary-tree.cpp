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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        if(root->left == NULL && root->right == NULL){
            vector<int> tmp;
            tmp.push_back(root->val);
            ans.push_back(tmp);
            return ans;
        }
        map<int ,map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int , int>>> que;
        que.push({root , {0, 0}});
        while(!que.empty()){
            auto p = que.front();
            que.pop();
            TreeNode* node = p.first;
            int x = p.second.first ;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                que.push({node->left ,{x-1 , y+1}});
            } 
            if(node->right){
                que.push({node->right ,{x+1 , y+1}});
            }

        }
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());

            }
            ans.push_back(col);
        }
        return ans;
        
    }
};