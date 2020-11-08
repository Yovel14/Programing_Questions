length = int(input())

if length ==0: print(0)
else:
    mx = 0
    CurrentLength = 1
    prev = float('inf')
    for item in (int(n) for n in input().split()):
        if item>prev:
            CurrentLength+=1
            prev = item
        else:
            prev = item
            if CurrentLength>mx: mx = CurrentLength
            CurrentLength = 1
    if CurrentLength>mx: print(CurrentLength)
    else: print(mx)