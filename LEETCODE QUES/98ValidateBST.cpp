/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(n
        if(root==NULL){ullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int>inorder(TreeNode*root , vector<int>&res){  
    if(root==NULL){
        return res;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right , res);
    return res;
}
    bool isValidBST(TreeNode* root) {
       if(root==NULL){
           return NULL;
       }
       vector<int>res;
       res= inorder(root , res);
       for(int i=1;i<res.size();i++){
           if(res[i]<=res[i-1]) return false;
       }
       return true;
    }


};

