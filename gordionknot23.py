def fun(n,r):
    p=1
    i=1
    while i<=n:
        p=p*i
        i=i+1
    q=1
    i=1
    while i<=r:
        q=q*i
        i=i+1
    t=1
    i=1
    while i<=n-r:
        t=t*i
        i=i+1
    return p/(q*t)
n=12
n2=19
s=0
i=0
while i<=12:
    r=i
    a=fun(n,r)
    b=(fun(n2,7))
    print i,n,n2
    s=s+a*(b-1)
    n=n+1
    n2=n2-1
    i=i+1
print s
