import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    m=int(x[1])
    k=len(x[1])
    n=0
    j=0
    while j<k:
       n=n*10+int(x[0][j])
       j=j+1
    num=pow(10,k-1)
    while j<len(x[0]):
        print n*m
        n=n%num
        n=n*10+int(x[0][j])
        j=j+1
    print n*m
    i=i+1
