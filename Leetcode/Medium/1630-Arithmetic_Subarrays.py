'''
Idea 1:
    an observation can be made that if an array is sorted than the deffrence of each two tdjacent elements can be equal

Idea 2:
    to be an arithemtic array need to be of the form
    a, a+d, a+2d, a+3d.....a+(length-1)d
    this is the form of arithmetic series thus we can use there qualities
    Sum formula: (n(a_1+a_n))/2
    meaning:
        min(ls) = a
        max(ls) = a+(length-1)d
        max(ls)-min(ls)=(length-1)d
        meaning: ( max(ls)-min(ls))%(length-1)=0
    
    and there index can be found using the difrence of max and min
    difrence for the series = (max-min)/(length-1)
    index = (value-min)/dif
    thus we can create a list for the indexes and see if there is a repeted indexes
'''

def checkArithmeticSubarrays(self, nums, l, r):
    def isArithmetic(ls):
        if len(ls)<2: return True
        ls.sort()
        d = ls[1]-ls[0]
        for i in range(1,len(ls)):
            if ls[i]-ls[i-1]!=d: return False
        return True
    return [isArithmetic(nums[l[i]:r[i]+1]) for i in range(len(r))]