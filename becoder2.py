sav = [[-1 for x in range(1000)] for x in range(1000)]

def fun(n,k,sav):
    if n==0 and k==0:
        return 1
    if k==0 or n==0:
        return 0
    if sav[n][k]==-1:
        if sav[n-1][k]==-1:
            sav[n-1][k]=fun(n-1,k,sav)
        if sav[n-1][k-1]==-1:
            sav[n-1][k-1]=fun(n-1,k-1,sav)
        sav[n][k]=k*sav[n-1][k]+sav[n-1][k-1]
    return sav[n][k]


fac=[1]
i=1
while i<=105:
    fac.append(fac[i-1]*i)
    i=i+1
Matrix = [[0 for x in range(1000)] for x in range(1000)]
i=1
while i<10:
    j=0
    while j<10:
        Matrix[i][j]=fac[i]/(fac[j]*fac[i-j])
        j=j+1
    i=i+1
i=1
while i<10:
    j=1
    while j<=i:
        n=i
        k=j
        if sav[n][k]==-1:
            if sav[n-1][k]==-1:
                sav[n-1][k]=fun(n-1,k,sav)
            if sav[n-1][k-1]==-1:
                sav[n-1][k-1]=fun(n-1,k-1,sav)
            sav[n][k]=k*sav[n-1][k]+sav[n-1][k-1]
        print sav[n][k]
        j=j+1
    i=i+1


#print fac
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    k=int(x[2])
    j=1
    mp=m
    sm=0
    while j<=k:
        l=0
        sr=sav[n][j]
        sm=sm+sr*(mp/fac[j])
        mp=mp*(m-j)
        j=j+1
    print sm
    i=i+1
