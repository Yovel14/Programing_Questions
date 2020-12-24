'''
Idea:
    run over each bit from the end and add it to the answer veriable
'''




def reverseBits(n):
    ans = 0
    for i in range(31,-1,-1):
        
        #if n&1:
        #    ans|=1<<i
        #istead of checking I can just add n&1 which might be 1 or 0 depending on n
        ans|=(n&1)<<i
        n>>=1
    return ans