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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // RECURSIVE->
        postorder(root, ans);




        // ITERATIVE ->
        // 2STACK
        // if(root == NULL) return ans;
        // stack<TreeNode*> st1 , st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     root = st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root->left != NULL){
        //         st1.push(root->left);
        //     }
        //     if(root->right != NULL){
        //         st1.push(root->right);
        //     }

        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }



        // 1 stack
        // if(root == NULL) return ans;
        // stack<TreeNode*> st;
        // TreeNode* curr = root;
        // while(curr != NULL  || !st.empty()){
        //     if(curr != NULL){
        //         st.push(curr);
        //         curr = curr->left;
        //     }
        //     else{
        //         TreeNode* temp = st.top()->right;
        //         if(temp == NULL){
        //             temp = st.top();
        //             st.pop();
        //             ans.push_back(temp->val);
        //             while(!st.empty() && temp == st.top()->right){
        //                 temp = st.top();
        //                 st.pop();
        //                 ans.push_back(temp->val);
        //             }
        //         }
        //         else{
        //             curr = temp;
        //         }
        //     }
        // }
















        return ans;
    }


// RECURSIVE APPROACH
private:
    void postorder(TreeNode* node, vector<int>& ans) {
        if (node == NULL)
            return;
        postorder(node->left, ans);
        postorder(node->right, ans);
        ans.push_back(node->val);
    }
};