'''
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
'''

'''
idea: 
    creating 2 nested loops for a and b and c will be generated from a and b (c = 1000 - a - b) 
    loop on b only on range(a,0) so pairs of numbers will not repeat
    in the inner loop  check if a^2+b^2=c^2
note: creating numbers of sum to 1000 is faster than checking for numbers in the form of pythagorean triplet(a^2+b^2=c^2)

limits: since a,b,c are natrual and their sum is 1000 than they are smaller than 1000 and bigger than 0 (0 isn't a natrual number)
'''
def find_product_of_pythagorean_triplet_whose_sum_is_1000():
    for a in range(1,1000):
        for b in range(1,a+1):
            c = 1000-a-b
            if a*a+b*b==c*c:
                return a*b*c
    return -1
print(find_product_of_pythagorean_triplet_whose_sum_is_1000())



'''Fast solution without probraming based on the posible represanttio of pythongoram triplets
(a, b, c) = ( (m2-1), (2m), (m2+1))
for explantaion (https://www.storyofmathematics.com/pythagorean-triples)


#solution by Pier
Without programming:

a= 2mn; b= m^2 -n^2; c= m^2 + n^2;
a + b + c = 1000;

2mn + (m^2 -n^2) + (m^2 + n^2) = 1000;
2mn + 2m^2 = 1000;
2m(m+n) = 1000;
m(m+n) = 500;

m>n;

m= 20; n= 5;

a= 200; b= 375; c= 425;
'''