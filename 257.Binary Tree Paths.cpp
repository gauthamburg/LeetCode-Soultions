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
    vector<string> result;

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;
        string curr = to_string(root->val);  
        recsn(root, curr);
        return result;
    }

    void recsn(TreeNode* car, string curr) {
        if (isLeaf(car)) {
            result.push_back(curr);
            return;
        }

        if (car->left) {
            recsn(car->left, curr + "->" + to_string(car->left->val));
        }

        if (car->right) {
            recsn(car->right, curr + "->" + to_string(car->right->val));
        }
    }

    bool isLeaf(TreeNode* car) {
        return car->left == nullptr && car->right == nullptr;
    }
};
