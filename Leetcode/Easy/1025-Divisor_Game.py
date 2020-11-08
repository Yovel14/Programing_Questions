# Memozation
global ls
ls = [None]*1001
def divisorGame(n):
    if n<=1: return False
    if ls[n]!=None:
        return ls[n]
    for i in range(n//2+1,0,-1):
        if n%i==0:
            if ( not divisorGame(n-i)):
                ls[n] = True
                return True
    ls[n] = False
    return False

# math
# the base case is n = 2
# alice choses 1 and bob gets 1 thus alice wins
# so purpose is to check if alice can take bob to 1
# if n is even than she takes out 1 thus bob gets odd number
# alice can do it again and again thus bob will get at the end the smallest positive odd number 1
# and since this is the method to win bob will try to do the same
# thus alice can only win if she recives an even number
def divisorGame(n):
    return n&1^1 # check if n is positive with bitwise operations
    return n%2==0# chick if n is positive with arithmetic operations