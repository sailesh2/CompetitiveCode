x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
mod=1000000007
if n%2==0 and m%2!=0:
    if m==1:
        ans=pow(2,n,mod)
    else:
        if k==1:
            ans=1
        else:
            ans=0
elif n%2!=0 and m%2==0:
    if n==1:
        ans=pow(2,m,mod)
    else:
        if k==1:
            ans=1
        else:
            ans=0
elif n%2==0 and m%2==0:
    p=(m-1)*(n/2)
    ans=pow(2,p,mod)
else:
    if k==1:
        p=(m-1)*(n/2)
        ans=(n*pow(2,p,mod))%mod
    else:
        p=(2*m-2)*(n/2)
        ans=pow(2,p,mod)
print ans
