def fun(a,sav):
    if a==1:
        return 0
    if a==0:
        return 1
    if sav[a-1]==-1:
        sav[a-1]=fun(a-1,sav)
    if sav[a-2]==-1:
        sav[a-2]=fun(a-2,sav)
    return (a-1)*(sav[a-1]+sav[a-2])
n=input()
sav=[-1]*100
sav[0]=1
sav[1]=0
i=0
while i<n:
    a=input()
    if sav[a]==-1:
        if sav[a-1]==-1:
            sav[a-1]=fun(a-1,sav)
        if sav[a-2]==-1:
            sav[a-2]=fun(a-2,sav)
        sav[a]=(a-1)*(sav[a-1]+sav[a-2])
        print sav[a]
    else:
        print sav[a]
    i=i+1
