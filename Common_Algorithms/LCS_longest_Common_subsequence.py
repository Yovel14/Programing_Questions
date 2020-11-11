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
