'''
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
'''
PrimeLs = (2, 3, 5, 7, 11, 13, 17, 19)
dic = {}#count for the max amount of times a prime is a multiple of a number
for i in range(2,21):
    t = i
    for j in PrimeLs:
        if t ==1:
            break
        pcount = 0
        while t%j==0:
            t//=j
            pcount+=1
        dic[j] = max(dic.get(j,0),pcount)
ans = 1
for k,v in dic.items():#get the min
    ans*=(k**v)
print(ans)