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