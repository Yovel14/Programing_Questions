n = int(input())
def devide(n):
    return any([n !=2 and i!=2 and i%2==0 and (n-i)%2==0 for i in range(2,n+1,2)])
print('YES' if devide(n) else 'NO')