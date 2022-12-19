class Solution {
public:
TreeNode  *left ,*right;

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }  
        queue<TreeNode*>q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if(left==NULL && right==NULL){
                continue;
            }
            if(left==NULL || right ==NULL){
                return false;
            }
            if(left->val!=right->val){
                return false;
            }
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }  
        return true;    
    }
};
// Recursive Approach
bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return helper(p->left,q->right) && helper(p->right, q->left); 
    }