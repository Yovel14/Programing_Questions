n, t = tuple(map(int,input().split()))

s = input()
for _ in range(t):
    i = 1
    while i < n:
        if s[i-1] == 'B' and s[i] == 'G':
            if i ==n-1:
                temp = ''
            else: temp = s[i+1:]
            s = s[:i-1] + 'GB'+temp
            i+=2
        else: i+=1
print(s)