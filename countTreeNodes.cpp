class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr) return 1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
