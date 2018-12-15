import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    thr=int((3*math.floor(float(b)/3))-(3*math.ceil(float(a)/3)))/3+1
    fiv=int((5*math.floor(float(b)/5))-(5*math.ceil(float(a)/5)))/5+1
    ft=int((15*math.floor(float(b)/15))-(15*math.ceil(float(a)/15)))/15+1
    print thr-ft,fiv-ft,ft
    i=i+1
