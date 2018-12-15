import math
n=int(raw_input())
i=0
k=0
while i<n:
    y=raw_input().split(' ')
    s=int(y[0])
    d=int(y[1])
    if k<s:
        k=s
    else:
        x=int(math.floor((float(k-s))/d))+1
        k=s+x*d
    i=i+1
print k
