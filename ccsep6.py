import math
global mod
global a

a=[]
ans=[0]

def func():
    for i in range(0,1010):
        t=[0]*(i+1)
        a.append(t)
        for j in range(0,len(t)):
            if j==0 or j==i:
                a[i][j]=1
            else:
                a[i][j]=(a[i-1][j-1]+a[i-1][j])%mod
def fun(n):
#    a=(6*n**5+15*n**4+10*n**3+n)/30.0
    a=[]
    k=4
    n_k = []
    n_k.append(n)
    for i in range(1,k+1):
        t = (pow(n+1,i+1,mod) - 1)%mod
        s = 0 
        for j in range(2,i+2):
            s+=(a[i+1][j]*n_k[i+1-j])%mod
        n_k.append(   (  (   (t-s)%mod  ) * pow(a[i+1][1],mod-2,mod)  )%mod  )
    print n_k[-1]
    return n_k[-1]
#    return int(a)

t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    mod=m
    func()
    s=0
    j=1
    while j<=n:
        p=int(math.floor(float(n)/j))
        k=int(math.floor(float(n)/p))
        #print j,p
        q=fun(k)-fun(j-1)
        s=(s+((q )*(p ))) 
        j=k+1
    print s 
    i=i+1
