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
     vector<vector<int>> v;
    void print(vector<int> v1){
        for(int i=0;i<v.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    void find(TreeNode* root,int targetSum,vector<int> v1){
         // print(v1);
         if(root==NULL){
            return;
         }
         cout<<root->val<<" ";
        if(root->left==NULL&&root->right==NULL&&targetSum==root->val){
            v1.push_back(root->val);
            v.push_back(v1);
        }
        v1.push_back(root->val);
        find(root->left,targetSum-root->val,v1);
        find(root->right,targetSum-root->val,v1);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v1;
        find(root,targetSum,v1);
        return v;
    }
};