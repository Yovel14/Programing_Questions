'''
Idea:
    One observation:
        is that if we think about which lights will be changing their status
        the lights will change there status are lights which we turn an odd number of times
        to find which lights we change an odd number of times
        we change a light when the light’s place is  a multiple of another number `a` as `a` is `1....n`
        which means only lights with an odd number of divisors will be on at the end

    Second observation:
        numbers with an odd number of divisors have a whole square root
        Explanation:
            the square root of a number is multiplied by itself thus it has an odd amount of devisors because we can divide each multiple into pairs

    third observation:
        the amount of numbers below n with an odd number of divisors is sqrt of n and round down to a whole number
        Explanation:
            we need to count the square roots below n
            1^2+2^2+3^2+5^2.... = 1,4,9,14,25...

            if we want to generate all the perfect squares below n we run from 1 to sqrt of n and round down to a whole number
            but since we just want the amount we can just take the sqrt of n and round down to a whole number

'''

from math import sqrt#math.sqrt is faster than n**0.5
def bulbSwitch(n):
    return int(sqrt(n))