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
    // returns {rob_this, not_rob_this}
    pair<int,int> robHouse(TreeNode* root) {
        if (!root) return make_pair(0, 0);

        pair<int,int> left = robHouse(root->left);
        pair<int,int> right = robHouse(root->right);

        // If we rob this node, we cannot rob its children
        int robThis = root->val + left.second + right.second;

        // If we don’t rob this node, we can choose max from robbing or not robbing children
        int notRobThis = max(left.first, left.second) + max(right.first, right.second);

        return make_pair(robThis, notRobThis);
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> ans = robHouse(root);
        return max(ans.first, ans.second);
    }
};
