class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preorderIdx = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;

        // Pick root from preorder
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int mid = inorderIndex[rootVal];

        // Build left and right subtree
        root->left = buildTreeHelper(preorder, left, mid - 1);
        root->right = buildTreeHelper(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map inorder values to indices
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};
