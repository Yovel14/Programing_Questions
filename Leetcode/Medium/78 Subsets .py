def subsets(self, nums: List[int]) -> List[List[int]]:
    ls = []
    length = len(nums)
    for mask in range(2**length):
        t = []
        for i in range(length):
            if (mask>>i)&1: t.append(nums[i])
        ls.append(t)
    return ls