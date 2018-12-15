i=1
mod=1000000007
fac=[1]
while i<=1000010:
    fac.append((fac[i-1]*i)%mod)
    i=i+1

t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])

    print (fac[k]*pow(8,k,mod))%mod
    i=i+1
