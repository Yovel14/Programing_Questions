ans = 0
home = {}
guest = {}
for _ in range(int(input())):
    h,g = tuple(map(int,input().split()))
    home[h] = home.get(h,0)+1
    guest[g ] = guest.get(g,0) +1

for k,v in home.items():
    ans+=v*guest.get(k,0)
print(ans)