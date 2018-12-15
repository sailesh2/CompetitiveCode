import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    a2=math.sqrt(a)
    b2=math.sqrt(b)
    s=int(math.floor(b2))-int(math.floor(a2))
    if int(math.floor(a2))==(a2):
        s=s+1
    print s
    i=i+1
