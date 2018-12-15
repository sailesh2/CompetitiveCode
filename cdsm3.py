import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    l=int(x[0])
    b=int(x[1])
    if l==1 or l==2:
        l=1
    else:
        cnt=0
        j=2
        while j<=int(math.ceil(l**0.5)):
            if l%j==0:
                cnt=1
                break
            j=j+1
        if cnt==0:
            l=l-1
            if l==2:
                l=1
    if b==1 or b==2:
        b=1
    else:
        cnt=0
        j=2
        while j<=int(math.ceil(b**0.5)):
            if b%j==0:
                cnt=1
                break
            j=j+1
        if cnt==0:
            b=b-1
            if b==2:
                b=1
    print l*b
    i=i+1
