class Solution {
public:
    bool sameTree(TreeNode* a, TreeNode* b) {
        // both null → identical
        if (!a && !b) return true;

        // one null → not identical
        if (!a || !b) return false;

        // values differ
        if (a->val != b->val) return false;

        // check both subtrees
        return sameTree(a->left, b->left) &&
               sameTree(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
