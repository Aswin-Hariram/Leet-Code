class Solution {
public:
    int first;
    long long second = LLONG_MAX;

    void dfs(TreeNode* root) {
        if (!root) return;

        if (root->val > first && root->val < second)
            second = root->val;

        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        first = root->val; //first smallest
        dfs(root);

        return second == LLONG_MAX ? -1 : second;
    }
};
