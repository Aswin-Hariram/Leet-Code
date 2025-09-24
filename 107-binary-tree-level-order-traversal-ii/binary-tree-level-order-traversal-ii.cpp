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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; // ✅ handle empty tree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level; // store current level nodes

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val); // add current node value

                if (node->left) q.push(node->left);   // push left child
                if (node->right) q.push(node->right); // push right child
            }

            ans.push_back(level); // add level to result
        }

        reverse(ans.begin(), ans.end()); // ✅ reverse to get bottom-up order
        return ans;
    }
};
