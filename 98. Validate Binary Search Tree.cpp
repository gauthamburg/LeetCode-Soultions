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
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        return recsn(root,LONG_MIN,LONG_MAX);
    }

    bool recsn(TreeNode* root,long l,long r){
        if(!root)return true;
        int ret=true;

        if(root->val <= l || root->val >= r){
            ret=false;
        }

        int chil=(recsn(root->left,l,root->val) && recsn(root->right,root->val,r));

        return (chil && ret);

    }
};