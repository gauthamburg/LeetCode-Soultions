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
    int diamax=0;

    int height(TreeNode* root){
        if(!root)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        diamax=max(diamax,lh+rh);
        return 1+max(lh,rh);       
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diamax;
    }
};