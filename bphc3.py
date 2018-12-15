import math


t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    l=int(x[0])
    r=int(x[1])
    lt=int(math.ceil(((1+8*l)**0.5-1)/2))
    rt=int(math.ceil(((1+8*r)**0.5-1)/2))
    tsm=(rt-1)*(rt)/2-(lt)*(lt+1)/2
    if (rt-1)%2==0:
        tsmeven=((rt-1)/2)*((rt-1)/2+1)
    else:
        tsmeven=((rt-2)/2)*((rt-2)/2+1)
    if lt%2==0:
        tsmeven=tsmeven-(lt/2)*(lt/2+1)
    else:
        tsmeven=tsmeven-((lt-1)/2)*((lt-1)/2+1)
    tsm=tsm-tsmeven
    lleft=l-(lt*(lt-1))/2-1
    rleft=r-(rt*(rt-1))/2
    if lleft%2!=0:
        if lt%2==0:
            tsm=tsm-lt
    else:
        if lt%2!=0:
            tsm=tsm+lt
    if rleft%2!=0:
        tsm=tsm+rt
    print tsm
    i=i+1
    
