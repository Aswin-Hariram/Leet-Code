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
    int totalTilt = 0;
    int sum(TreeNode* node){
        if(!node) return 0;

        int leftsum = sum(node->left);
        int rightsum = sum(node->right);
        totalTilt += abs(leftsum-rightsum);
        return leftsum + rightsum + node->val;

    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        sum(root);
        return totalTilt;

    }
};