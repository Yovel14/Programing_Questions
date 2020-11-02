'''
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
(https://projecteuler.net/problem=2)
'''

#brute force
def fib1():
    a,b = 1,2
    Sum = 0
    while a<4000000:
        if (a&1)^1:
            Sum+=a
        a,b = b,a+b
    return Sum
print(fib1())

#using mathematics
# one observation is that every 3rd number is even 
# maybe there is a ways to calculate the n%3 ==0 one after the other
# F_n  = F_n-1+F_n-2 = 
# F_n-2 + F_n-3 + F_n-3 + F_n-4 = 
# F_n-3 +F_n-4 + F_n-3 +F_n-3 + F_n-4 = 
# 3F_n-3 + 2F_n-4 = 
# 3F_n-3 + F_n-4 + F_n-5 + F_n-6 = (F-n-4 = F_n-5 + F_n-6
# 4F_n-3 + F_n-6 (F_n-3 = F_n-4 + F_n-5

def fib2():
    f_n_3 = 2#F_n-3
    f_n_6 = 0#F_n-6
    Sum = 0
    while f_n_3<4000000:
        Sum+=f_n_3
        
        t = 4*f_n_3+f_n_6
        f_n_6 = f_n_3
        f_n_3 = t
    return Sum