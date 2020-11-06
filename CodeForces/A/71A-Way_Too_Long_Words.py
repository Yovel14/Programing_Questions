def TooLong(s):
    return s if len(s)<11 else s[0]+str(len(s)-2)+s[-1]

for i in range(int(input())):
    print(TooLong(input()))