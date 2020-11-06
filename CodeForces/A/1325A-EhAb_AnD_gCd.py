# lcm = a*b/gcd
# lcm +gcd = x
# a*b/gcd + gcd = x
# a*b + gcd^2 = x*gcd
# since a,b>0 then a*b+ gcd^2 > 0 and we know that x > 0 then gcd > 0
# we can put number we want instead of gcd so we will be able to calculate a spisific a,b
# set gcd = 1
# a*b+1 = x*1
# a*b = x-1

# when solving we set gcd to 1 so its 1+lcd = x
# lcd = x-1
# so a and b are 1 ,x-1

for _ in range(int(input())):
    print(1,int(input())-1)


# intresting propreties:
# gcd(1,n) = 1
# lcd(1,n = n