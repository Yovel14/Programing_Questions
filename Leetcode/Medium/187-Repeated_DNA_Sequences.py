'''
Idea:
    create a set for all length of 10 str 
    check if its already exists in 
'''


def findRepeatedDnaSequences(s):
    length = len(s)
    if length<10:
        return []
    # using a sliding window and a ls to gather previulsy used 10 digit squences
    se = set()#set for all str of length 10
    r = set()#set for all repeating str of length 10
    for i in range(0,length-9):
        current = [i:i+10]
        if current in se: r.add(current)
        else: se.add(current)
    return r