n=int(input())

ctr=0
while 1:
    print(n)
    sqrt=int(n**0.5)
    sq=sqrt*sqrt
    cnt=0
    if sq==n:
        n=sqrt
        cnt=1
        ctr=ctr+1
    if cnt==0:
        i=2
        while i<=int(n/2):
            if (i*i)%n==0:
                n=i
                ctr=ctr+2
                cnt=1
                break
            i=i+1
    if cnt==0:
        break
print(n,ctr)
