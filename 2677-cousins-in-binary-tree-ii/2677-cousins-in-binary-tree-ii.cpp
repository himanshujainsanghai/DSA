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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return NULL;

         
        // queue<TreeNode*> que;
        // que.push(root);
        // vector<int> lvlsum;
        // while(!que.empty()){
        //     int n = que.size();
        //     int cntsum =0;
        //     while(n--){
        //     TreeNode* node = que.front();
        //     que.pop();

        //     cntsum += node->val;

        //     if(node->left){
        //         que.push(node->left);

        //     }
        //     if(node->right){
        //         que.push(node->right);
        //     }

        //     }
        //     lvlsum.push_back(cntsum);
        // }

        // que.push(root);
        // root->val =0;
        // int i=1;

        // while(!que.empty()){
        //     int n = que.size();

        //     while(n--){
        //         TreeNode* node = que.front();
        //         que.pop();

        //         // siblings
        //         int sibsum = (node->left != NULL)?node->left->val : 0;
        //         sibsum += (node->right != NULL)? node->right->val :0;

        //         if(node->left){
        //             node->left->val = lvlsum[i]-sibsum;
        //             que.push(node->left);
        //         }
        //         if(node->right){
        //             node->right->val = lvlsum[i]-sibsum;
        //             que.push(node->right);
        //         }

        //     }

        //     i++;
        // }

        // OPTIMAL APPROACH -->O(N);

        queue<TreeNode*> que;
        que.push(root);
         
        int lvlsum = root->val;
        while(!que.empty()){
            int n = que.size();
            int nxtlvlsum =0;

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                node->val = lvlsum - node->val;

                int sibsum = (node->left != NULL)?node->left->val : 0;
                sibsum += (node->right != NULL)? node->right->val :0;

                if(node->left){
                    nxtlvlsum += node->left->val;
                    node->left->val = sibsum;
                    que.push(node->left);
                }
                if(node->right){
                    nxtlvlsum += node->right->val;
                    
                    node->right->val = sibsum;
                    que.push(node->right);
                }
            }
            lvlsum = nxtlvlsum;
        }


        return root;
        



    }
};