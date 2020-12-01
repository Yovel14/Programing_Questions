n = int(input())
ls = list(map(int,input().split()))

print((n-1)//2)
ls.sort()
ReturnLs = []

i = 0
for j in range(n//2,n):
    ReturnLs.append(ls[j])
    if i !=n//2:
        ReturnLs.append(ls[i])
    i+=1
print(*ReturnLs)