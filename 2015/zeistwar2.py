t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n1=int(x[0])
    n=0
    while n1>0:
        n=n*10+n1%10
        n1=n1/10
    m1=int(x[1])
    m=0
    while m1>0:
        m=m*10+m1%10
        m1=m1/10
    ans=n+m
    sm=0
    while ans>0:
        sm=sm*10+ans%10
        ans=ans/10
    print sm
    i=i+1
