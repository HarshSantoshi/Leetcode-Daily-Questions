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
TreeNode*helper(vector<int>&nums , int left , int right ){
    if(left>right){
        return NULL;
    }
    int mid = (left +right)/2;
    TreeNode*temp = new TreeNode(nums[mid]);
     temp->right = helper(nums , mid+1 , right);
    temp->left = helper(nums, left , mid-1);
   
    return temp;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums ,0 , n-1);  
    }
};


