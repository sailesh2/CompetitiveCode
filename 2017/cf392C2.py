inp=raw_input().split(' ')
n=int(inp[0])
m=int(inp[1])
k=int(inp[2])
x=int(inp[3])
y=int(inp[4])

if n==1:
    d=k/m
    r=k%m
    mind=d
    maxd=d
    if r!=0:
        maxd=maxd+1
    if r>=y:
        a=maxd
    else:
        a=mind
    print maxd,mind,a
else:
    p=(n*m)

    if k<p:
        mind=0
        maxd=1
        r=k%m
        d=k/m
        if d<x:
            if d<x-1:
                a=mind
            else:
                if r>=y:
                    a=maxd
                else:
                    a=mind
        else:
            a=maxd
        print maxd,mind,a
    elif k==p:
        d=k/p
        print d,d,d
    else:

        k=k-(n*m)
        d=k/((n-1)*m)
        r=k%((n-1)*m)
        mind=d/2+d%2+1
        maxd=d+1
        
        if r!=0:
            if d%2!=0:
                if r/n>0:
                    maxd=maxd+1
            else:
                maxd=maxd+1

        if x==1:
        if r<x:
            a=mind
        elif r>x:
            a=maxd
        else:
            k=k-d*m
            if x>1:
                k=k-(x-1)*m
            if k>=y:
                a=maxd
            else:
                a=mind


        print maxd,mind,a
