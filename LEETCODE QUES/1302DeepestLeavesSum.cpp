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
int ans =0;

    int heightTree(TreeNode*root){
        if(root==NULL){
            return 0;
        }

        return max(heightTree(root->left) , heightTree(root->right) ) + 1;
    }

    void solve(TreeNode*root  , int height){
        if(root==NULL){
            return ;
        }
        if(root->left == NULL && root->right ==NULL && height==1){
            ans+=root->val;
            return;
        }
        if(root->left){
            solve(root->left , height-1);
        }
        if(root->right){
            solve(root->right  , height -1);
        }
        return ;
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = heightTree(root);

        solve(root , height);
        return ans;
    }
};
