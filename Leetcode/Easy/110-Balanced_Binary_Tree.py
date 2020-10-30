'''
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true


Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104
(https://leetcode.com/problems/balanced-binary-tree/)
'''
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