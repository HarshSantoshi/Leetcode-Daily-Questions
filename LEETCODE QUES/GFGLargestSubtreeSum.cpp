class Solution {
  public:
  int SubtreeSum(Node*root , int &ans){
      if(root==NULL)return 0;
      int leftSum = SubtreeSum(root->left , ans);
      int rightSum = SubtreeSum(root->right , ans);
      int totalSum = root->data + leftSum + rightSum;
      ans = max(ans , totalSum);
      return totalSum;
  }
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        //Write your code here
        int ans = INT_MIN;
        SubtreeSum(root, ans);
        return ans;
    }
};
