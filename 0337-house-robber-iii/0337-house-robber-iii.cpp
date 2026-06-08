/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    // Helper function jo har node par [Rob_Money, Skip_Money] ka pair return karega
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        // Post-order traversal: Pehle bacchon ka decision lekar aao
        pair<int, int> leftSubtree = solve(root->left);
        pair<int, int> rightSubtree = solve(root->right);
        
        int robCurrent = root->val + leftSubtree.second + rightSubtree.second;
        int skipCurrent = max(leftSubtree.first, leftSubtree.second) + 
                          max(rightSubtree.first, rightSubtree.second);
        
        return {robCurrent, skipCurrent};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        
        return max(result.first, result.second);
    }
};