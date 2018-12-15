import math
n=input()
a=2**(int(math.floor(math.log(n,10)))+1)
sm=a
a=1
while n>0:
    b=n%10
    if b==7:
        sm=sm+a
    a=a*2
    n=n/10
print sm-1
