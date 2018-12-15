def fun(n,m):
    p=1%m
    s=p
    p=10
    k=1
    while 1:
        if 2*k-1>n-1:
            break
        s=((s%m)+((p%m)*(s%m))%m)%m
        p=((p%m)*(p%m))%m
        k=k*2
    if n-k>=1:
        s=((s%m)+(((p%m)*(fun(n-k,m)%m))%m))%m
    return s


t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    p=1%m
    s=p
    p=10
    k=1
    while 1:
        if 2*k-1>n-1:
            break
        s=((s%m)+((p%m)*(s%m))%m)%m
        p=((p%m)*(p%m))%m
        k=k*2
    if n-k>=1:
        s=((s%m)+(((p%m)*(fun(n-k,m)%m))%m))%m
    print s%m
    i=i+1
