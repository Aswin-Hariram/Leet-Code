# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def inorder(self, cur, res):
        if not cur:
            return
        self.inorder(cur.left, res)
        res.append(cur.val)
        self.inorder(cur.right, res)

    def inorderTraversal(self, root):
        res = []
        self.inorder(root, res)
        return res
