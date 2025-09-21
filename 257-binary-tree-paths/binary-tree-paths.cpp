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
    void btp(TreeNode* node, string path, vector<string> &ans) {
        if (!node) return;

        // Add current node to path
        if (!path.empty()) path += "->";
        path += to_string(node->val);

        // If leaf node, push to ans
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }

        // Recurse left and right
        if (node->left) btp(node->left, path, ans);
        if (node->right) btp(node->right, path, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        btp(root, "", ans);
        return ans;
    }
};
