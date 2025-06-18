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
    TreeNode* invertTree(TreeNode* root) {
        typedef struct TreeNode* node;
        node curr=root;
        if(!root){
            return NULL;
        }
         
        if(curr->left && curr->right){
            if(!curr->left->left && !curr->left->right && !curr->right->left && !curr->right->right){
               node temp=curr->left;
               curr->left=curr->right;
               curr->right=temp;
               return curr;
            }
        }
        
        curr->left=invertTree(curr->left);
        curr->right=invertTree(curr->right);
        node temp=curr->left;
        curr->left=curr->right;
        curr->right=temp;

        return root;
    }
};