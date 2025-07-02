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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recsn(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* recsn(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (preStart >= preorder.size() || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, rootVal) - inorder.begin();
        int leftSize = inRootIndex - inStart;

        root->left = recsn(preorder, inorder, preStart + 1, inStart, inRootIndex - 1);
        root->right = recsn(preorder, inorder, preStart + 1 + leftSize, inRootIndex + 1, inEnd);

        return root;
    }
};
