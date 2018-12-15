t=input()
i=0
while i<t:
    m=input()
    x=raw_input().split(' ')
    n=int(x[0])
    has=[0]*1001
    ctr=0
    j=1
    while j<=n:
        mini=1000000
        cnt=0
        if has[j]==0:
            k=j+1
            while k<=n:
                if has[k]==0:
                    val=int(x[j])+int(x[k])
                    if val<=m:
                        if m-val<mini:
                            cnt=1
                            mini=m-val
                            save=k
                k=k+1
            if cnt==1:
                has[save]=1
                ctr=ctr+1
            else:
                if int(x[j])<=m:
                    ctr=ctr+1
        has[j]=1
        j=j+1
    print ctr
    i=i+1
