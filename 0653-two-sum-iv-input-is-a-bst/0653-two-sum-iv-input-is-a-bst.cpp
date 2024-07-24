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

class BSTIterator{
    private:
    stack<TreeNode*> st;
    bool reverse = true;
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }

    }
    public:
    BSTIterator(TreeNode* root , bool isrev){
        reverse = isrev;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();

    }

    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        // next
        BSTIterator l(root , false);
        //for  before()
        BSTIterator r(root , true);

        int i = l.next();
        int j = r.next();  //r.before

        while(i<j){
            if(i +j == k) return true;
            else if(i+j <k) i = l.next();
            else j = r.next();
        }
        return false;
        
    }
};