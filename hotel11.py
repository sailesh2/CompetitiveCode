
def fun(n,k,ctr,sav):
    
    if n==0:
        return 0
    if ctr==k:
        return 1
    sm=0
    i=1
    while i<=n:
        if sav[n-i][ctr+1]==-1:
            sm=sm+fun(n-i,k,ctr+1,sav)
        else:
            sm=sm+sav[n-i][ctr+1]
        i=i+1
    sav[n][ctr]=sm
    return sav[n][ctr]
sm=0
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
sav = [[-1 for x in range(104)] for x in range(104)]
sm=fun(n,k,1,sav)
if sm==0:
    print "-1"
else:
    print sm%10000007
