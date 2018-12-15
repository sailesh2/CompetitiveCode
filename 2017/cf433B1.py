import math
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
if k==0:
    print "0 0"
else:
    a=float(3*k-n)/2
    if a<0:
        a=0
    else:
        a=int(math.ceil(a))

    if n-(k-a)*3==a:
        cnt=0
    else:
        if a>0:
            cnt=1
        else:
            cnt=0
    if k==n:
        mini=0
    else:
        mini=1
        
    print mini,2*(k-a)+cnt
    
