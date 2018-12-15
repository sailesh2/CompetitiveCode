t=input()
while t>0:
    n,m=map(int,raw_input().split())
    sum=0
    while n>0:
        s=1
        k=1
        p=10
        while 2*k<=n:
            s=(s+s*p)%m
            k=(k*2)
            p=(p*p)%m
        m1=n-k
        x=n-m1
        sum=((sum*pow(10,x,m))%m+s)%m
        n=m1
    print sum
    t-=1
