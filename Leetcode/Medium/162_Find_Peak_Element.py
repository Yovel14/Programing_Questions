'''
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Follow up: Your solution should be in logarithmic complexity.
'''
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





