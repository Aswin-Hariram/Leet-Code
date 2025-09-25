class Solution {
private:
    bool preorder(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // both null => same
        if (!p || !q) return false; // one null, one not => different
        
        if (p->val != q->val) return false;
        
        bool leftsame = preorder(p->left, q->left);
        bool rightsame = preorder(p->right, q->right);
        
        return leftsame && rightsame;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);
    }
};
