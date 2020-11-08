Money = [1,5,10,20,100][::-1]# since from index 0 to the last(before reverse) they are divisable greedy approach can be used

m = int(input())# giveng amount
BillCount = 0
for bill in Money:
    BillCount+=m//bill
    m%=bill
print(BillCount)