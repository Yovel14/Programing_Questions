s = int(input())+1
while True:
    if len(str(s)) == len(set(str(s))):
        break
    s+=1
print(str(s))