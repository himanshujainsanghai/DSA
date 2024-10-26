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
    int height[100001];
    int level[100001];
    int maxhgt[100001];
    int sndmaxhgt[100001];
    int func(TreeNode* node, int lvl) {
        if(!node){
            return 0;
        }

        level[node->val] = lvl;
        height[node->val] = max(func(node->left , lvl+1) , func(node->right , lvl+1)) +1;


        if(maxhgt[lvl] < height[node->val]){
            sndmaxhgt[lvl] = maxhgt[lvl];
            maxhgt[lvl] = height[node->val];
        }
        else if(sndmaxhgt[lvl]< height[node->val]){
            sndmaxhgt[lvl] = height[node->val];
        }

        return height[node->val];


        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        func(root , 0);
        vector<int> ans;

        for(auto &node:queries){
            int l = level[node];

            int temp = l + ((maxhgt[l] == height[node])? sndmaxhgt[l]:maxhgt[l]) -1;

            ans.push_back(temp);
        }

        return ans;
    }
};