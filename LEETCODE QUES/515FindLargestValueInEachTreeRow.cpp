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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size  = q.size();
            int maxData =INT_MIN;
            while(size--){
                TreeNode* front = q.front();
                maxData = max(maxData  , front->val);
                q.pop();
                if(front->right)q.push(front->right);
                if(front->left)q.push(front->left);
            }
            ans.push_back(maxData);
        }
        return ans;
    }
};
