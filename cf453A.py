from decimal import *
import math
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
i=1
s=0
while i<n:
    s=s+math.pow(float(i)/n,k)
    i=i+1
print "%.12f" % ((n-s))
