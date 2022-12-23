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
vector<int>inorder(TreeNode*root , vector<int>&res){
    if(root==NULL)
        return res;
    

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
    return res;
}
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return -1;
        vector<int>res;
        inorder(root ,res);
         return res[k-1];
    }
};
