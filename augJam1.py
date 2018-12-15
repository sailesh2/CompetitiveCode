t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    ind=int(x[0])
    n=int(x[1])
    if n==0:
        print ind
    else:
        if ind==1:
            if n%2==0:
                print "1"
            else:
                print "0"
        else:
            if n%2==0:
                print "0"
            else:
                print "1"
    i=i+1
        
