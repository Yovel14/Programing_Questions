'''
Idea:
    need to count differences
'''


def minFlips(target):
    # the target is to find how many diffrences there are for example
    # the first state is '0'
    # 111 you need to switch all from index 0 to end
    # 1010 you need to switch at index 0,1,2,3
    last = '0'
    ans = 0
    for i in target:
        if i!=last:
            last = i
            ans+=1
    return ans