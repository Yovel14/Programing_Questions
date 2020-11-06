n = int(input())
count = 0
for _ in range(n):
    s = input()
    if s.count('1')>1:
        count+=1
print(count)