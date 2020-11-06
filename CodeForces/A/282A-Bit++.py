x = 0
for _ in range(int(input())):
    s = input()
    if s[0] == 'X' or s[0] =='x':
        if s[1] =='+':
            x+=1
        else: x-=1
    else:
        if s[0] =='+':
            x+=1
        else: x-=1
print(x)