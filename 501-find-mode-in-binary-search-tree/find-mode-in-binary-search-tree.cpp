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
    vector<int> result;
    int maxCount = 0, currCount = 0;
    TreeNode* prev = nullptr;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);

        if (prev && prev->val == root->val) {
            currCount++;
        } else {
            currCount = 1;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            result.clear();
            result.push_back(root->val);
        } else if (currCount == maxCount) {
            result.push_back(root->val);
        }

        prev = root;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};
