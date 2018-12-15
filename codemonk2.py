import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    c=int(x[2])
    k=int(x[3])
    if (b*b-4*a*(c-k))<0:
        print "0"
    else:
        print int(math.ceil((((b*b-4*a*(c-k))**0.5)-b)/(2*a)))
    i=i+1
