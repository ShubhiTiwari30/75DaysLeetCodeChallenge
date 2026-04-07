class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        postorder(root->left, ans);      // LEFT
        postorder(root->right, ans);     // RIGHT
        ans.push_back(root->val);      // ROOT
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
