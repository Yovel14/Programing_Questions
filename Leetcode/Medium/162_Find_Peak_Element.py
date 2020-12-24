'''
Idea:
    using binary search to find peak
    check for if nums[mid]>nums[mid+1] then pick is in the second half becuase there is a rise
'''

#find peak through iteration
def findPeakElement1(nums = []):
    low = 0
    high = len(nums)-1
    while low<high:
        mid = low +(high-low)//2
        if nums[mid]<nums[mid+1]:
            low  = mid+1
        else: high = mid
    return low


#find peak through recursion
def findPeakElement2(nums,low = 0,high = -1):
    if high ==-1: high = len(nums)-1
    if low == high: return low
    mid = low+(high-low)//2
    if nums[mid]<nums[mid+1]:
        return findPeakElement2(nums,mid+1,high)
    return findPeakElement2(nums,low,mid)