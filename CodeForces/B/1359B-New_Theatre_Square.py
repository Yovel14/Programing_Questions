for _ in range(int(input())):
    n,m,x,y = (int(l) for l in input().split())
    #print(n,m,x,y)
    # n - lines 
    # m - charecters
    smallest = min(2*x,y)
    cost = 0
    for _ in range(n):
        ls = input()
        #print(ls)
        i = 0
        while i < m:
            # * black
            # . white
            if ls[i] == '.':
                if i+1<m and ls[i+1] =='.':
                    cost+=smallest
                    i+=2
                else: 
                    cost+=x
                    i+=1
            else: i+=1
    print(cost)