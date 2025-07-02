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
    vector<int> traversal;
public:
    int kthSmallest(TreeNode* root, int k) {
        travel(root);
        return traversal[k-1];
    }
    void travel(TreeNode* root){
        if(!root)return;
        travel(root->left);
        traversal.push_back(root->val);
        travel(root->right);
    }
};