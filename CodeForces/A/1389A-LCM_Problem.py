for _ in range(int(input())):
    l,r = map(int,input().split())
    if 2*l<=r:
        print(l,2*l)
    else: print(-1,-1)