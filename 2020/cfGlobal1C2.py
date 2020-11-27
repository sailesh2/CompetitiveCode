import math
def nextp(n):
    ctr=0
    p=1
    while n>0:
        ctr=ctr+p
        p=p*2
        n=n//2
    return ctr

q=int(input())

i=0

while i<q:
    n=int(input())
    ans=nextp(n)
    if ans==n:
        print('1')
    else:
        print(ans)
    i=i+1
