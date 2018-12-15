import math

t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    print int(math.floor(math.pow(b,0.5)))-int(math.ceil(math.pow(a,0.5)))+1
    i=i+1
