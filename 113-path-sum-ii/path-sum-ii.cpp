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
    void findpath(TreeNode* root, vector<int> &path, vector<vector<int>> &res, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        // Check if it's a leaf and targetSum matches
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(path);
        } else {
            findpath(root->left, path, res, targetSum - root->val);
            findpath(root->right, path, res, targetSum - root->val);
        }

        path.pop_back(); // backtrack
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        if (!root) return res;

        findpath(root, path, res, targetSum);
        return res;
    }
};
