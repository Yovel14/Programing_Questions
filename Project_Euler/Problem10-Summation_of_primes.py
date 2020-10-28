'''
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
(https://projecteuler.net/problem=10)
'''
'''
Idea:
    start from 5 and use the form of primes (2,3)#the sieve primality test would be faster
    check if a number is a Prime using a created list of primes
'''
import time
from math import sqrt
def SumPrimes(n):
    if n ==3 or n == 4: return [2,3][n-3]
    PrimeLs = [2,3]
    
    def isPrime(a):
        sq = sqrt(a)
        for i in PrimeLs:
            if i>sq: break
            if a%i==0: return False
        return True
    
    Sum = 5#5 becuase 2+3
    current = 1
    while PrimeLs[-1]<n:
        p = 6*current-1
        if p>n: break
        if isPrime(p):
            Sum+=p
            PrimeLs.append(p)
        p = 6*current+1
        if p>n: break
        if isPrime(p):
            Sum+=p
            PrimeLs.append(p)
        current+=1
    return Sum

print(SumPrimes(2000000))