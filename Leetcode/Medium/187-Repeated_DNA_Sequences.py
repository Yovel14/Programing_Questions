'''
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

Constraints:
    0 <= s.length <= 105
    s[i] is 'A', 'C', 'G', or 'T'.
(https://leetcode.com/problems/repeated-dna-sequences/)
'''
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