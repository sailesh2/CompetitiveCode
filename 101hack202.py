t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    k=b
    p=1
    s=0
    while k>0:
        a1=a/p
        b1=b/p
        if a1%2==0:
            bit=0
        else:
            if p*(a1+1)<=b:
                bit=0
            else:
                bit=1
        s=s+p*bit
        p=p*2
        k=k/2
    print s
    i=i+1
