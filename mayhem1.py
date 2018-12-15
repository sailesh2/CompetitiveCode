t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    k=0
    mini=10000000
    while k<n:
        ctr=0
        num=int(x[k])
        while num!=0:
            if num%2==1:
                ctr=ctr+1
            num=num/2
        if ctr<=mini:
            mini=ctr
        k=k+1
    print mini
    i=i+1
