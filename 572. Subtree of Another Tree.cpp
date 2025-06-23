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
    bool ind=false;
public:
    void recsn(TreeNode* p,TreeNode* q,bool &ret){
        if(!p && !q){
            return;
        }
        if(p && q){
            if(p->val!=q->val){
                ret=false;
                return;
            }
        }
        else if(!p && q){
            ret=false;
            return;
        }
        else if(!q && p){
            ret=false;
            return;
        }

        recsn(p->left,q->left,ret);
        recsn(p->right,q->right,ret);
    }

    bool issame(TreeNode* p,TreeNode* q){
        bool ret=true;
        recsn(p,q,ret);
        return ret;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(issame(root,subRoot)){
           ind=true;
           return ind;
        }
        if(root->left)isSubtree(root->left,subRoot);
        if(root->right)isSubtree(root->right,subRoot);

        return ind;

    }
};