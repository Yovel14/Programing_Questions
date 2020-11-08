# -1+2-3+4-5+6...(n is even)
# calculate every two values together
# 1+1+1...
# n/2 amount of 1
# sum of it is n/2

# -1+2-3+4-5....(n is odd)
# 1   +1  -5
# (n-1)/2 ones + -n
# (n-1)/2 *1 was calculated
# sum is (n-1)/2 -5
n = int(input())
if n%2==0: print(n//2)
else:
    print((n-1)//2-n)
