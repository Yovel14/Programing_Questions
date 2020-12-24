'''
Idea:
    solution based on binary search
    test between day 1 to the max day of the list
    test mid and respond until low high
'''

def minDays(b, m, k):
    #Solution based on binary search meaning I will try each day from 1 to max(b) until 1 is low
    #k flowers per bouquet
    #m number of bouquet

    if m*k >len(b):
        return -1

    def NumberofBouquetsInADay(n):
        CountFllowersPerSycle = 0
        TotalCount = 0
        for d in b:
            if d<=n:
                CountFllowersPerSycle+=1
            else:
                TotalCount+=CountFllowersPerSycle//k
                CountFllowersPerSycle=0
        return TotalCount + CountFllowersPerSycle//k

    #Binary search
    low = 1
    high = max(b)
    while low<high:
        mid = low +(high-low)//2
        if NumberofBouquetsInADay(mid)<m:
            low = mid+1
        else: high =mid
    return low