import math
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
v=2**(len(bin(n)[2:]))-1
if k==1:
    print n
else:
    print v
