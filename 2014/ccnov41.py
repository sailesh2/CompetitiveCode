t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    k=int(x[2])
    p=1
    j=1
    while j<=n:
        p=p*pow(j,j)
        j=j+1
    j=1
    while j<=k:
        r=input()
        p1=1
        l=1
        while l<=r:
            p1=p1*pow(l,l)
            l=l+1
        p2=1
        l=1
        while l<=n-r:
            p2=p2*pow(l,l)
            l=l+1
        print (p/(p1*p2))%m
        j=j+1
    i=i+1
