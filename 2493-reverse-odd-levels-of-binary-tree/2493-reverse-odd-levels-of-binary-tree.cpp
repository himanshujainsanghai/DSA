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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while(!que.empty()){
            int n = que.size();
            vector<TreeNode*> levelnodes;
            while(n--){
                TreeNode* temp = que.front();
                que.pop();

                levelnodes.push_back(temp);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }

            }


            if(level%2 == 1){
                // odd level

                int i=0 , j = levelnodes.size()-1;
                while(i<j){
                    int value = levelnodes[i]->val;
                    levelnodes[i]->val = levelnodes[j]->val;
                    levelnodes[j]->val = value;
                    i++;
                    j--;
                }


            }
            level++;
        }


        return root;
        
    }
};