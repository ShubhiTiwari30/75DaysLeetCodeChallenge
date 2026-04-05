class Solution {
public:
    unordered_map<int, int> indexMap;
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = indexMap[rootVal];

        // IMPORTANT: build right subtree first
        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};
