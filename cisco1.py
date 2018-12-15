t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    if m<n:
        print "NO"
    else:
        a=pow(10,n)*((pow(10,m-n+1)-1)/9)
        if a>1000000:
            print "YES"
        else:
            print "NO"
    i=i+1
