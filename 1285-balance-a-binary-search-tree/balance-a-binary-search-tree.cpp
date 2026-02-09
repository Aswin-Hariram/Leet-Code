class Solution {
public:
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(vals[mid]);

        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vals.clear();
        inorder(root);

        return build(0, vals.size() - 1);
    }
};
