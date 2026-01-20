class Solution {
public:
    unordered_set<int> seen; //5 3 2 

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        if (seen.count(k - root->val))
            return true;

        seen.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
