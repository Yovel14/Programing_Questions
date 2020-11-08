'''
# brute force
s = input()

length  = len(s)
count = 0
for i in range(0,length):
    if s[i] =='Q':
        for j in range(i+1,length):
            if s[j] == 'A':
                for l  in range(j+1,length):
                    if s[l] == 'Q':
                        count+=1
print(count)
'''

# dynamic programing

s = input()
qcount  = 0
combinations = 0
count = 0
for c in s:
    if c == 'Q':
        count+=combinations
        qcount+=1
    elif c == 'A':
        combinations+=qcount
print(count)