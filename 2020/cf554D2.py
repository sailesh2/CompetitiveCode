import math

x=input().split(' ')
a=int(x[0])
b=int(x[1])

diff=max(a,b) - min(a,b)

if diff==0:
    print(diff)
else:
    next= int(math.ceil(min(a,b)/diff))
    next=next*diff
    next=next-min(a,b)
    print(next)
