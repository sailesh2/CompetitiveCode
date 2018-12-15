t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    c=int(x[2])
    mod=1000000009
    print (k*((n*n*(n-1))/2-((n-1)*n*(2*n-1))/6)+c*((n*(n-1))/2))%mod
    i=i+1
