t=input()
i=0
while i<t:
    n=input()
    j=0
    cnt=0
    lt1=list()
    while j<n:
        x=raw_input()
        lt1.append(x)
        s1=""
        if j==0:
            s=""
            k=0
            while k<len(x):
                if x.find(x[k])==k:
                    s=s+x[k]
                k=k+1
            lt=list(set(x))
            lth=len(lt)
            arr= [[0 for x in xrange(lth)] for x in xrange(n)]
        else:
            k=0
            while k<len(x):
                if x.find(x[k])==k:
                    s1=s1+x[k]
                k=k+1
            if s1!=s:
                cnt=1
        k=0
        while k<lth:
            arr[j][k]=lt1[j].count(s[k])
            k=k+1
        j=j+1
    if cnt==1:
        print "Case #"+str(i+1)+": Fegla Won"
    else:
        j=0
        mini=10000000        
        while j<n:
            sm=0
            k=0
            while k<n:
                if k!=j:
                    l=0
                    while l<lth:
                        sm=sm+abs(arr[k][l]-arr[j][l])
                        l=l+1
                k=k+1
            if sm<=mini:
                mini=sm
            j=j+1
        j=0
        sm=0
        while j<n:
            k=0
            while k<lth:
                sm=sm+arr[j][k]-1
                k=k+1
            j=j+1
        if sm<=mini:
            mini=sm
        print "Case #"+str(i+1)+": "+str(mini)
    i=i+1
