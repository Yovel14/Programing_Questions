side = input()
string = input()

n =  '''qwertyuiopasdfghjkl;zxcvbnm,./'''
l =  ''' qwertyuio asdfghjkl;zxcvbnm,./'''

r =  '''wertyuiop sdfghjkl; xcvbnm,./'''

dic = dict(zip(list(r) if side =='R' else list(l),n))# this could be made faster if this was premade
newa = []
for i in string:
    a = dic[i]
    newa.append(a)

print(''.join([dic[i] for i in string]))