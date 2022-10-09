class Solution {
public:
    vector<int> vec;
    void preorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        vec.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return vec;
    }
};
