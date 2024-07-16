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
// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root) return ans;

//     }

//     void trav(TreeNode* root , vector<vector<int>>& ans){
//         if(!root) return;
//         vector<int> temp;
//         temp.push_back(root->val);
//         if(root->left != NULL){
//             tarv(root->left , temp)
//         }
//         if(root->right != NULL) trav(root->right ,temp);
//     }
// };


class Solution {
public:
void Paths(TreeNode* a, string path, vector<string>& V) {
    if (!a)
        return;

    path += to_string(a->val);

    if (!a->left && !a->right)
        V.push_back(path);

    path += "->";
    Paths(a->left, path, V);
    Paths(a->right, path, V);
}

vector<string> binaryTreePaths(TreeNode* a) {
    vector<string> V;
    Paths(a, "", V);
    return V;
}
};