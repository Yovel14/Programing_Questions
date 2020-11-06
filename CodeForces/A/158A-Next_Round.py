n,k = map(int,input().split())# n,k
ls = input().split()
ls = [i for i in ls if int(i)>=int(ls[k-1]) and int(i)>0 ]
print(len(ls))