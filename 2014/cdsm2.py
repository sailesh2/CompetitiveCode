t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    print (n*(n-1)*(n-2))/6 - (k*(k-1)*(k-2))/6
    i=i+1
