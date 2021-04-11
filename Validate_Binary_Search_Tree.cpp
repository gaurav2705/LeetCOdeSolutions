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
    bool help(TreeNode* root,int k,int y){
        if(root==NULL){
            return true;
        }
        if(y==1){
            if(root->val>=k)
                return false;
            return help(root->left,k,y)&&help(root->right,k,y);
        }
        else{
            if(root->val<=k)
                return false;
            return help(root->left,k,y)&&help(root->right,k,y);
        }
        if(root->left!=NULL&&(root->left->val>=root->val)){
            return false;
        }
        if(root->right!=NULL&&(root->right->val<=root->val)){
            return false;
        }
        return isValidBST(root->left)&&isValidBST(root->right);

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left!=NULL&&(root->left->val>=root->val)){
            return false;
        }
        if(root->right!=NULL&&(root->right->val<=root->val)){
            return false;
        }
        if(!help(root->left,root->val,1)||!help(root->right,root->val,2)){
            return false;
        }
        return isValidBST(root->left)&&isValidBST(root->right);
    }
};
