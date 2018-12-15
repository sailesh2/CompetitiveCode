t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    sm=0
    j=1
    while j<=n:
        sm=sm+int(x[j])
        j=j+1
    sm=float(sm)/n
    ctr=0
    j=1
    while j<=n:
        if int(x[j])>sm:
            ctr=ctr+1
        j=j+1
    print ctr
    i=i+1
            
