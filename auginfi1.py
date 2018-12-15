import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    if k==int(math.ceil(float(n)/2))-1:
        print n-1
    elif k<int(math.ceil(float(n)/2))-1:
        print 2*k+1
    else:
        print 2*(n-1-k)
    i=i+1
