# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSame(self, l, r):
        if not l and not r:  # both None
            return True
        if not l or not r:   # one is None, mismatch
            return False
        if l.val != r.val:   # values differ
            return False
        # check mirror condition
        return self.isSame(l.left, r.right) and self.isSame(l.right, r.left)

    def isSymmetric(self, root):
        if not root:
            return True
        return self.isSame(root.left, root.right)
