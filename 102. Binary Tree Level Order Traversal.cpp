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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {}; 
        }
        
        vector<vector<int>> answer;
        vector<int> rv;
        queue<TreeNode*> aon; 
        aon.push(root);
        
        while (!aon.empty()) {
            int size = aon.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = aon.front();
                aon.pop();
                level.push_back(node->val);
                
                if (node->left) {
                    aon.push(node->left);
                }
                if (node->right) {
                    aon.push(node->right);
                }
            }
            answer.push_back(level);
        }
        
        return answer;
    }
};
