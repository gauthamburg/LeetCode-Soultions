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
    bool issame=true;
    void traversal(TreeNode* p,TreeNode* q){
        if(p && q){
            if(p->val!=q->val){
                issame=false;
                return;
            }
        }
        else if(p && !q){
            issame=false;
            return;
        }
        else if(!p && q){
            issame=false;
            return;
        } 
        if(p && q)traversal(p->left,q->left);
        if(p && q)traversal(p->right,q->right);              
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traversal(p,q);
        return issame;
    }
};