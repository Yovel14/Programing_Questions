'''
Idea:
    run with two indexes i,j. i from the start j from the end
    if reached ' '(space) add 1 to i or remove 1 from j
note: not to count spaces and symbles in the check but to count numbers
'''

def isPalindrome(s):
    i,j = 0,len(s)-1
    while i<j:
        if not s[i].isalnum():
            i+=1
            continue
        if not s[j].isalnum():
            j-=1
            continue
        if s[j].lower()!=s[i].lower():
            return False
        i+=1
        j-=1
    return True