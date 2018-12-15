def cal(n,m):
    mod=998244353
    s=0
    if n==1:
        s=(1+m)%mod
    else:
        s=0
        i=2
        p=1
        while i<=n and m>=0:
            s=(s+(p*(1+m+(m*m)%mod)%mod)%mod)%mod
            p=m
            m=m-1
            i=i+1
    return s


x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
c=int(x[2])

sab=cal(a,b)
sac=cal(a,c)
sbc=cal(b,c)
mod=998244353
print sab,sac,sbc
print (((sab*sac)%mod)*sbc)%mod
