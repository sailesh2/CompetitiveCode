import math
x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
a=int(math.ceil(math.ceil(float(n)/2)/m))*m
if a>n:
    print "-1"
else:
    print a
