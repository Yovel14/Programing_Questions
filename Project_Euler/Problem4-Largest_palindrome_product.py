'''
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
(https://projecteuler.net/problem=4)
'''
def isPalindrome(n):
    t = str(n)
    length = len(t)
    for i in range(length//2):
        if t[i]!=t[length-1-i]: return False
    return True
m = -1
for a in range(999,99,-1):
    if a*a<m:
        break
    t = (a//11)*11#To get number lower than `a` devisable by 11 but reciving the closest number
    for b in range(t,99,-11):#-1 11 and not -1  becuase see *1
        t = a*b
        if t<m:
            continue
        elif isPalindrome(t): m = t

print(m)
'''*1
The palindrome can be written as:

abccba

Which then simpifies to:

100000a + 10000b + 1000c + 100c + 10b + a

And then:

100001a + 10010b + 1100c

Factoring out 11, you get:
'''