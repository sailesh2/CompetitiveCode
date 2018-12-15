t=input()
i=0
while i<t:
    n=input()
    print "case "+str(i+1)+":",
    
    if n==1:
        print "1 1"
    else:
        cnt=0
        ctr=3
        l=2
        r=4
        while 1:
            if n>=l and n<=r:
                break
            l=r+1
            ctr=ctr+2
            r=l+ctr-1
            cnt=1-cnt
        if cnt==0:
            mid=(l+r)/2
            if n==mid:
                print ctr/2+1,ctr/2+1
            elif n<mid:
                print n-l+1,ctr/2+1
            else:
                print ctr/2+1,r-n+1
        else:
            mid=(l+r)/2
            if n==mid:
                print ctr/2+1,ctr/2+1
            elif n<mid:
                print ctr/2+1,n-l+1
            else:
                print r-n+1,ctr/2+1
    i=i+1
