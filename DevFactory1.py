t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    k=int(x[0])
    n=int(x[1])
    ans=(k**(n+1)-1)/(k-1)
    sm=0
    while ans!=0:
        sm=sm+ans%10
        ans=ans/10
    print sm
    i=i+1
