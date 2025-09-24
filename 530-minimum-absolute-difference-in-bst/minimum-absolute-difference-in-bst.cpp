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
private:
    int ans = INT_MAX;       // store minimum difference
    TreeNode* prev = nullptr; // store previous node during inorder traversal

    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);

        if (prev) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
