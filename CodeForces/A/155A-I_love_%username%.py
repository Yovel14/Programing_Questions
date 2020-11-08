length = int(input())
ls = [int(n) for n in input().split()]
if length <1: print(0)
else:
    ans = 0
    mi = ls[0]
    mx = ls[0]
    for n in ls:
        if n<mi:
            mi = n
            ans+=1
        elif n>mx:
            mx = n
            ans+=1
    print(ans)