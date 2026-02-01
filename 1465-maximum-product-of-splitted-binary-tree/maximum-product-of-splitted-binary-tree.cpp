class Solution {
public:
    vector<long long> subtreeSums;

    long long computeSubtreeSum(TreeNode* node) {
        if (!node) return 0;

        long long leftSum  = computeSubtreeSum(node->left);
        long long rightSum = computeSubtreeSum(node->right);

        long long currentSubtreeSum = node->val + leftSum + rightSum;

        subtreeSums.push_back(currentSubtreeSum);

        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        computeSubtreeSum(root);

        long long totalTreeSum = subtreeSums.back();
        long long maximumProduct = 0;

        for (long long subtreeSum : subtreeSums) {
            long long remainingTreeSum = totalTreeSum - subtreeSum;
            maximumProduct = max(
                maximumProduct,
                subtreeSum * remainingTreeSum
            );
        }

        return maximumProduct % 1000000007;
    }
};
