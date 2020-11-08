c1 = tuple(c for c in input())
successful = False
for ctemp in (tuple(c for c in card) for card in input().split()):
    if c1[0] == ctemp[0] or c1[1]==ctemp[1]:
        successful = True
        break
if successful: print('YES')
else: print('NO')