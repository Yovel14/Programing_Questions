n = int(input())
ls = list(map(int,input().split()))

ls.sort()
ReturnLs = []

i = 0
for j in range(n//2,n):
    ReturnLs.append(ls[j])
    if i !=n//2:
        ReturnLs.append(ls[i])
    i+=1
count = 0
for i in range(1,n-1,2):
    if ReturnLs[i]<ReturnLs[i+1] and ReturnLs[i-1]>ReturnLs[i]:
        count+=1
print(count)
print(*ReturnLs)