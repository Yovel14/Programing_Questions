'''
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.



Example 1:

[[1,3,5,7]
[10,11,16,20]
[23,30,34,60]]

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true

Example 2:

[[1,3,5,7]
[10,11,16,20]
[23,30,34,60]]

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false

Example 3:

Input: matrix = [], target = 0
Output: false

(https://leetcode.com/problems/search-a-2d-matrix/)
'''
'''
Idea:
    find the possible column
    search the cloumn for the number
note: both searches are made using binary search
'''

def searchMatrix( m, t):
    if m ==[] or m ==[[]]:
        return False
    row = 0
    low = 0
    high = len(m)-1
    while low<=high:
        mid = low+(high-low)//2
        if m[mid][-1]==t:
            return True
        if m[mid][-1]>t:
            row = mid
            high = mid-1
        else: low = mid+1

    low = 0
    high = len(m[row])-1
    while low<=high:
        mid = low+(high-low)//2
        if m[row][mid]==t:
            return True
        if m[row][mid] <t:
            low = mid+1
        else: high = mid-1
    return False