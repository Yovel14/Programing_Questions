def GetSet():
    s = input()
    if len(s) >1: return set(s.split()[1:])
    return set()
if int(input())==len(GetSet().union(GetSet())): print('I become the guy.')
else: print('Oh, my keyboard!')