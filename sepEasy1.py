import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    k=int(x[2])
    a1=k*int(math.ceil(float(a)/k))
    b1=k*int(math.floor(float(b)/k))
    s=int(float(b1-a1)/k)+1
    print s
    i=i+1
