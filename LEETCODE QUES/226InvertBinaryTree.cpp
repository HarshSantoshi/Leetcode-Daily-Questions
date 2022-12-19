class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//Or 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // The following is basically equivalent to:
        // if (!root) return root;
        // TreeNode* temp = invertTree(root->left);
        // root->left = invertTree(root->right);
        // root->right = temp;
        // return root;
        TreeNode* temp;
        return root ? (temp = invertTree(root->left), root->left = invertTree(root->right), root->right = temp, root) : root;
    }
};