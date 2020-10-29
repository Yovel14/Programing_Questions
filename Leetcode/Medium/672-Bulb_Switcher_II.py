'''
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

    1. Flip all the lights.
    2. Flip lights with even numbers.
    3. Flip lights with odd numbers.
    4. Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...


Example 1:

Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]


Example 2:

Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]


Example 3:

Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].

Note: n and m both fit in range [0, 1000].
'''
'''
Note:
    Doing the same operation twice will reset the light

Idea:
    from the change of lights seaquens we can see there might be pattern o 3 since rule 4 and 
    after checking in examples we can see every three lights the pattern repeats
    so we will work on (n if n>3 else n)
    
    try preducing all pssibilities:#n in this cases if after taking min
        #those steps can be made using a software
        
'''

def flipLights(n,m):
    if m ==0: return 1
    n = min(n,3)
    se = set()
    for i in range(0,(1<<4),1):
        if bin(i).count('1')==m:
            ls = []
            for j in range(1,n+1):
                t = 1
                t^=(i&1)#rule1
                
                if j%2==0 and (i&(1<<1)):#rule2
                    t^=1
                    
                if  j%2!=0 and (i&(1<<2)):#rule3
                    t^=1
                    
                if (j-1)%3==0 and (i&(1<<3)):#rule4
                    t^=1
                ls.append(t)
            print(tuple(ls))
            se.add(tuple(ls))
    return len(se)
print(flipLights( n = 3, m = 1))