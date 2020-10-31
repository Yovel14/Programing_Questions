'''
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
'''
'''
Solution1:
    got with two indexes from each side and find where there is no match
    where there is no match we can check if we remove one char if there will be a palindrom

Solution2:
    find the first difference using a veriation of binary search
'''

def validPalindrome(s):
    i = 0
    j = len(s)-1
    while i<=j:
        if s[i]!=s[j]: break
        else:
            i+=1
            j-=1
    if i>j: return True
    
    if s[i+1:j+1:] == s[j:i:-1]: return True
    
    if s[i:j]==s[i:j:-1]: return True
    
    return False


def validPalindrome(s):
    l = 0 
    h = len(s)-1
    c = len(s)//2
    while l<h:
        if s[l:l+c] == s[h:h-c:-1]:
            l += c
            h -= c
        elif c <= 1:#when c ==1 the error must be on low or high index
            t = s[l+1:h+1]
            if t ==t[::-1]: return True
            t = s[l:h]
            return t ==t[::-1]
        else: c//=2
    return True