n,d = (int(x) for x in input().split())
s = input()
startIndex = 0
count = 0
CanBeDone = True
while startIndex<n-1:
    LastIndex = startIndex+d
    if LastIndex>=n:
        count+=1
        break
    while LastIndex>startIndex:
        if s[LastIndex]=='1':
            break
        LastIndex-=1
    
    if LastIndex==startIndex:
        CanBeDone =  False
        break
    else: 
        count+=1
        startIndex = LastIndex
if CanBeDone: print(count)
else: print(-1)