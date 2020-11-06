# in order for a number to be able to become 1 from multiplying by 2 or divding by 6 
# the numbers must be able if we miltiply by 2 sum amount of time to be devisable by 6
# in order for a number to be devisable by 6 it needes to be devisable by its compositoin 2,3
# since we can multiply my two we assume we hve infinit amount of 2
# but we have 3 only the amount in the number it self
# we can understand that for a number to get to 1 eventually it needs to have more 3 than 2  and not be a composit of other prime

# count how many times number is devisable by 3
# count how many times number is devisable by 2
# make sure the remaning number is 1 and count3 >= count 2
# and return count2 + 2*(count3 - count2)
# 2*(count3 - count2) is for every time there is a need to multiply by 2 and devide by 6

def FindCount2(n):# slow
    count3 =0
    count2 =0
    while n%3==0:
        count3+=1
        n//=3
    
    while n%2==0:
        count2+=1
        n//=2
    if n!=1 or count2>count3:
        return -1
    return count2+2*(count3-count2)


def FindCount(n):# faster
    count6 =0
    count3 = 0
    while n%6==0:
        count6+=1
        n//=6
    
    while n%3==0:
        count3+=1
        n//=3
    return -1 if n!=1 else count6+2*count3# same return just less calculation


for _ in range(int(input())):
    print(FindCount(int(input())))