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

    void solve(TreeNode* L , TreeNode* R , int level){
        if(L == NULL || R == NULL){
            return;
        }

        if(level%2 == 1){
            int value = L->val;
            L->val = R->val;
            R->val = value; 
        }

        solve(L->left , R->right , level +1);
        solve(L->right , R->left , level+1);

    } 
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        // BFS Approach
        // queue<TreeNode*> que;
        // que.push(root);
        // int level = 0;

        // while(!que.empty()){
        //     int n = que.size();
        //     vector<TreeNode*> levelnodes;
        //     while(n--){
        //         TreeNode* temp = que.front();
        //         que.pop();

        //         levelnodes.push_back(temp);
        //         if(temp->left){
        //             que.push(temp->left);
        //         }
        //         if(temp->right){
        //             que.push(temp->right);
        //         }

        //     }


        //     if(level%2 == 1){
        //         // odd level

        //         int i=0 , j = levelnodes.size()-1;
        //         while(i<j){
        //             int value = levelnodes[i]->val;
        //             levelnodes[i]->val = levelnodes[j]->val;
        //             levelnodes[j]->val = value;
        //             i++;
        //             j--;
        //         }


        //     }
        //     level++;
        // }


        // return root;



        // DFS Approach

        solve(root->left , root->right , 1);
        return root;
        
    }
};