t=input()
i=0
while i<t:
    n=input()
    ctr=0
    s=0
    p=1
    while n>0:
        num=1-(n%2)
        s=s+p*num
        p=p*2
        n=n/2
        ctr=ctr+1
    while ctr<32:
        s=s+p
        p=p*2
        ctr=ctr+1
    print s
    i=i+1
