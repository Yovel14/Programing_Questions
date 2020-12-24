'''
Solution:
    make a list of how much of each value in arr
    return how many values remain after removing k elements
'''

from collections import Counter
def findLeastNumOfUniqueInts(self, arr, k):
    arr = Counter(arr).values()
    u = len(arr)
    for i in sorted(arr):
        if i<=k:
            k-=i
            u-=1
        else: break
    return u