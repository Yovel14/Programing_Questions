def longestCommonSubsequence(self, s1, s2):
    length1 = len(s1)
    length2 = len(s2)
    temp  = [0]*(1+length1)
    ls = []
    for _ in range(length2+1):
        ls.append(temp.copy())
    
    for i in range(1,length1+1):
        for j in range(1,length2+1):
            if s1[i-1] == s2[j-1]:
                ls[j][i] = 1+ls[j-1][i-1]
            else: ls[j][i] = max(ls[j][i-1],ls[j-1][i])
    
    return ls[-1][-1]



def isSubsequence(s, t):# if the first ware to accure more than once there is a way that this will fail but that's is not the case this time
    i  = 0
    slength = len(s)
    for c in t:
        if i == slength: return True
        if i<slength:
            if c == s[i]:
                i+=1
    return i==slength