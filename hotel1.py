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
        print sav[n][k],
        j=j+1
    print
    i=i+1
print sav[4][2]
