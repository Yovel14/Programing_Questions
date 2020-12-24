'''
Idea:
    go to the end of the tree and and check on from front to back the hight difference
    because the function goes to the end and back its doesn't calculate anything twice thus the complexity is O(n) where n in the amount of Nodes
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def isBalanced(root,h = 1):
    def check(root,h = 1):#an helping function
        if not root: return 0
        l = check(root.right)
        if l ==-1: return -1
        r = check(root.left)
        if r ==-1: return -1
        if abs(r-l)>1: return -1
        return 1+max(l,r)
    return check(root)!=-1