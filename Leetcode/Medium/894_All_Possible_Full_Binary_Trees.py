#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def __init__(self):
        self.cache = {}
        self.cache[0] = []
        self.cache[1] = [TreeNode()]
    def allPossibleFBT(self, n: int) -> List[TreeNode]:# this could be done using tobulation
        if n%2==0: return []
        if n in self.cache: return self.cache[n]
        
        
        ans = []
        for i in range(1,n,2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(n-i-1)
            for l in left:
                for r in right:
                    ans.append(TreeNode(0,l,r))
        self.cache[n] = ans
        return ans



# tobulation

class Solution:
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        if n%2==0: return []
        cache = [[] for _ in range(n+1)]
        cache[1].append(TreeNode())
        
        for place in range(3,n+1,2):
            for i in range(1,place,2):
                for left in cache[i]:
                    for right in cache[place-1-i]:
                        cache[place].append(TreeNode(0,left,right))
        return cache[n]

