'''
Idea:
    run with count and add 1 for value '(' and remove 1 for value')' (while checking for max each time I add to ocount)
'''

def maxDepth(s):
    ocount = 0#count the depth of
    mcount = 0#reserves the dippest spot
    for i in s:
        if i=='(':
            ocount+=1
            if ocount>mcount: mcount = ocount
        elif i==')': 
            ocount-=1
    return mcount