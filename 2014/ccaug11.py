t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    y=raw_input().split(' ')
    j=0
    ctr=0
    while j<n:
        if int(y[j])%2==0:
            ctr=ctr+1
        j=j+1
    if k==0:
        if ctr==n:
            print "NO"
        else:
            print "YES"
    else:
        if ctr>=k:
            print "YES"
        else:
            print "NO"
    i=i+1
