def searchRange(nums, target):
    #solution using binary search
    def Find(a):#find possible ocurence of a
        length = len(nums)
        low = 0
        high = length-1
        possible_occurrence = length
        while low <=high:
            mid = low +(high-low)//2
            if nums[mid]>=a:
                possible_occurrence = mid
                high = mid-1
                continue
            else: low  = mid+1
        return possible_occurrence
    #note if target not in nums returns the same value as find(targer+1)
    FirstPos = Find(target)#find first occurence of target
    LastPos = Find(target+1)-1#find first occurence of target+1 and than remove one from the index to get last occurence of target
    return [FirstPos,LastPos] if FirstPos<=LastPos else [-1,-1]




#Another way to solve is to do two binary searches to find first and last

def searchRange(self, nums: List[int], target: int) -> List[int]:
    low = 0
    high = len(nums)-1
    occurrence = -1
    while low<=high: #find an occurrence(any occurrnce) of target
        mid = low +(high-low)//2
        if nums[mid]==target:#exiting for speed
            occurrence = mid
            break
        if nums[mid]>target:
            high = mid-1
        else: low = mid +1
    if occurrence ==-1:
        return [-1,-1]
    tHigh = high#To remember where  the max possible index for target is
    
    
    high = occurrence
    while low <high:#Find first occurrence
        mid = low +(high-low)//2
        if nums[mid]>=target:
            high = mid
        else: low = mid+1
    first_occurrence = low#To remember the first occurrence

    low = occurrence
    high = tHigh
    last_occurrence = occurrence
    while low<=high:#find last occurence
        mid = low +(high-low)//2
        if nums[mid] == target:# in nums[low] can't be a number lower than target so no need to check
            last_occurrence = mid
            low = mid+1
        else: high = mid-1
    return [first_occurrence,last_occurrence]