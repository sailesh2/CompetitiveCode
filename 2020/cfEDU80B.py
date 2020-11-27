import math

def getDigCnt(n):
    ctr=0
    while n>0:
        ctr=ctr+1
        n=n//10
    return ctr-1

t=int(input())
i=0
while i<t:
    x=input().split(' ')
    a=int(x[0])
    b=int(x[1])

    print(a*getDigCnt(b))
    i=i+1
