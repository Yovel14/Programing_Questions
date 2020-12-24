'''
Idea:
    run over releastTimes and keysPressed once and check for max
'''

def slowestKey(releaseTimes = [], keysPressed= ''):
    if keysPressed =='': return ''
    ans = releaseTimes[0],keysPressed[0]
    for i,( k,v) in enumerate(zip(keysPressed,releaseTimes)):
        ans = max(ans,(v-releaseTimes[i-1],k))
    return ans[1] 