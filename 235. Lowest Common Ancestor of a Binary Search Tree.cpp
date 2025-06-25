/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> pvec;
    vector<int> qvec;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ppath(root,p);
        qpath(root,q);
        int mins=min(pvec.size(),qvec.size());
        int i=0;
        int ansint;
        while(i<mins){
            if(pvec[i]!=qvec[i]){
                break;
            }
            i++;
        }
        ansint=pvec[i-1];
        TreeNode* curr=root;
        while(1){
            if(curr->val==ansint){
                return curr;
                break;
            }
            else if(curr->val<ansint){
                curr=curr->right;
            }
            else{              
                curr=curr->left;
            }

        }       
        
    }

    void ppath(TreeNode* root, TreeNode* tar){
        TreeNode* curr=root;
        while(1){
            if(curr->val==tar->val){
                pvec.push_back(curr->val);
                return;
                break;
            }
            else if(curr->val<tar->val){
                pvec.push_back(curr->val);
                curr=curr->right;
            }
            else{
                pvec.push_back(curr->val);               
                curr=curr->left;
            }

        }
    } 

    void qpath(TreeNode* root, TreeNode* tar){
        TreeNode* curr=root;
        while(1){
            if(curr->val==tar->val){
                qvec.push_back(curr->val);
                return;
                break;
            }
            else if(curr->val<tar->val){
                qvec.push_back(curr->val);
                curr=curr->right;
            }
            else{
                qvec.push_back(curr->val);               
                curr=curr->left;
            }

        }
    }  
};