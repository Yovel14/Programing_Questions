'''
Idea:
    get the lowest to the current position minus current and find the max of all calcutaled
'''

def maxProfit(prices):
    if len(prices)<2: return 0
    SmallestToNow = prices[0]
    Max = 0
    for p in prices:
        if p<SmallestToNow:
            SmallestToNow = p
            continue
        elif Max< p-SmallestToNow:
            Max = p-SmallestToNow
    return Max