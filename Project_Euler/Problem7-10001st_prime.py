'''
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
(https://projecteuler.net/problem=7)
'''
'''
idea: 
    using both the properties of primes that say:
        1. all Primes but 2,3 are of the form 6n+-1
        2. the lowest highest possible Prime factor of a number is its square root
    creating a list of prime to check if the next number is a prime and if the number is add to the list
    searching the list goest up to the square root of number checking
    checking only for number up of the form 6n+-1 since all Primes but 2,3 are of the form 6n+-1
'''

from math import sqrt


def find_the_nth_Prime(n):
    if n<=0: return -1
    if n==1: return 2
    if n==2: return 3
    
    
    PrimeLs = [2,3]
    n-=2# I already added 2 in the Prime Ls
    current = 1#index for 6n+-1(all primes but 2,3 are of the form 6n+1 or 6n-1)
    
    def isPrime(a):#check for primes previus to a
        sq = sqrt(a)#math.sqrt is faster than a**0.5
        for i in PrimeLs:
            if i >sq:#the largest Prime factor of a number is its square root
                return True
            if a%i==0: return False
        return True
    
    while n!=0:
        t = 6*current - 1
        if isPrime(t):
            PrimeLs.append(t)
            n-=1
            if n==0: break
        
        
        t = 6*current + 1
        if isPrime(t):
            PrimeLs.append(t)
            n-=1
        current+=1
    return t

print(find_the_nth_Prime(10001))