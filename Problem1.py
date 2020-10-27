'''
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
'''

def sol(n):
    n-=1
    n3 = n//3
    n5 = n//5
    n15 = n//15
    return (n3*(3+3*n3))//2+(n5*(5+5*n5))//2-(n15*(15+15*n15))//2
print(sol(1000))