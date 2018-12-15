import math
arr=[1,1,1,3,3,15,15,105,105,105,105]
mod=10**9
def fun(n):
    if n<=10:
        return arr[n]
    return ((pow(2,int(math.ceil(float(n)/4))))%mod)*((fun(int(math.ceil(float(n)/5))))%mod)*((fun(int(math.ceil(float(n)/10))))%mod)%mod
t=input()
i=0
while i<t:
    a=0
    n=input()
    b=fun(n)
    j=1
    while j<=5:
        k=1
        while k<=5:
            if j==1:
                a=max(a,pow(j*b,k*b,mod))
            elif j==2:
                if k==1 or k==3 or k==5:
                    a=max(a,pow(j*b,k*b,mod))
            elif j==3:
                if k!=3:
                    a=max(a,pow(j*b,k*b,mod))
            elif j==4:
                if k==1 or k==3 or k==5:
                    a=max(a,pow(j*b,k*b,mod))
            else:
                if k!=5:
                    a=max(a,pow(j*b,k*b,mod))
            k=k+1
        j=j+1
        
    if (b%mod)>a:
        a=b%mod
    print a
    i=i+1
