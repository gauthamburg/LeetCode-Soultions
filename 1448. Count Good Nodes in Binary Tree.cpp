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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
    int dfs(TreeNode* root,int maxsf){
        if(!root){
            return 0;
        }
        int retval=0;
        if(root->val >= maxsf){
            retval++;
        }
  

        int newMax=max(root->val,maxsf);
        retval+=dfs(root->left,newMax);    
        retval+=dfs(root->right,newMax);

        return retval;   
    }


};