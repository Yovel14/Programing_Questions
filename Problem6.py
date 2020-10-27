'''
The sum of the squares of the first ten natural numbers is,
1^2+2^2....+10^2 = 385

The square of the sum of the first ten natural numbers is,
(1+2+3..+10)^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025-385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
'''
def Difference_Of_Sums(n):
    a = (n*(n+1)*(2*n+1))/6 #sum of 1^2+2^+3^2...+n^2
    b = (n*(n+1))/2 #sum of 1+2+3+4...+n
    return b*b-a

print(int(Difference_Of_Sums(100)))