def minCostClimbingStairs(cost):# using dynamic programming tabulation
    prev,current = cost[0],cost[1]
    for n in cost[2:]:
        prev, current = current,n+min(prev,current)
    return min(prev,current)
    
    '''# useing the existing array
    for i in range(2,len(cost)):
        cost[i]+=min(cost[i-1],cost[i-2])
    return min(cost[-1],cost[-2])
    '''