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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        vector<long long> vis;
        queue<TreeNode*> que;
        que.push(root);
        vis.push_back(root->val);
        while(!que.empty()){
            int size = que.size();
            long long cnt=0;

            for(int i=0 ; i<size ; i++){
            TreeNode* node =que.front();
            que.pop();
            if(node->left != NULL){
                que.push(node->left);
                cnt += node->left->val;
            }
            if(node->right != NULL){
                que.push(node->right);
                cnt += node->right->val;
            }

            }
            if(cnt>0){

            vis.push_back(cnt);
            }
        }

        sort(vis.begin() , vis.end());
        if(k>vis.size()){
            return -1;
        }
        return vis[vis.size()-k];
        // return vis.size();
    }
};