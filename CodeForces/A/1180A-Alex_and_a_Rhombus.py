'''
n = int(input())
if n ==1: print(1)
else:
    current = 1
    for i in range(2,n+1):
        current +=4*(i-1)# an observation that from one to another that is the differance

    print(current)
'''

n  = int(input())
# is can be see that it is a series of odd numbers 1+3+5+...a_n...+5+3+1 so sum of first n odd numbers 2*Sum_a_n - a_n the minus is because it was counted twice because of the *2
# n*n is the sum of the first n odd numbers
# 1+(n-1)*2 is the last number in the series
print(2*n*n-(1+(n-1)*2))