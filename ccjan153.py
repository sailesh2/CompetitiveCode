t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    k=0
    sm=0
    j=0
    while j<n:
        if int(x[j])!=0:
            k=k+1
        sm=sm+int(x[j])
        j=j+1
    sm=sm-100
    if sm<0:
        print "NO"
    else:
        if k==0:
            print "NO"
        else:
            if float(sm)/k>=1:
                print "NO"
            else:
                print "YES"
    i=i+1
