t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    cnt=0
    j=0
    while j<n:
        el=int(x[j])
        if j==0:
            sm=int(x[1])
        else:
            sm=int(x[0])
        k=0
        while k<n:
            if k!=j:
                sm=sm&int(x[k])
            k=k+1
        if el==sm:
            cnt=1
            break
        j=j+1
    if cnt==1:
        print el
    else:
        print "-1"
    i=i+1
            
