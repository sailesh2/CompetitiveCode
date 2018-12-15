t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    print (10**k-1)*(10**(n-k)-1)
    i=i+1
