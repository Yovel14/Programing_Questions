'''
There are n bulbs that are initially off.
You first turn on all the bulbs. Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb.
Find how many bulbs are on after n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
(https://leetcode.com/problems/bulb-switcher/)
'''
'''
Idea:
    one observation:
        is that if we think about which lights will be change there status
        the lights will change there status are lights which we turn odd number of times
        to find the which lights we change odd number of times
        we change a light when light place is  a multiple of another number `a` as `a` is `1....n`
        which means only lights with odd number of devisors will be on at the end
    
    second observation:
        numbers with odd number of devisors have a whole square root
        Explanation:
            the square root of a number is multiplied by it self thus it has an odd amount of devisors
    
    third observation:
        the amount of numbers below n with odd number of devisors is sqrt of n and round down to a whole number
        Explanation:
            we need to count the square roots below n
            1^2+2^2+3^2+5^2.... = 1,4,9,14,25...
            
            if we want to generate all the pefect squares below n we run from 1 to sqrt of n and round down to a whole number
            but since we just want the amount we can just take the sqrt of n and round down to a whole number
'''

from math import sqrt#math.sqrt is faster than n**0.5
def bulbSwitch(n):
    return int(sqrt(n))