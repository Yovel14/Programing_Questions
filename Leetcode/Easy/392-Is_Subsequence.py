def isSubsequence(s, t):
    i  = 0
    slength = len(s)
    for c in t:
        if i == slength: return True
        if i<slength:
            if c == s[i]:
                i+=1
    return i==slength



def isSubsequence(s: str, t: str):# brute force - times out
    if s=='': return True
    if t =='': return False
    tlength = len(t)
    slength = len(s)
    if slength > tlength: return False
    for i in range(tlength):
        if t[i]==s[0]:
            if i ==tlength-1 and slength==1:
                return True
            if isSubsequence(s[1:],t[i+1:]):
                return True
    return False