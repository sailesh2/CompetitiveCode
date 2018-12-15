t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    if n%2==0:
        print "0"
    else:
        s=0
        j=0
        while j<n:
            s=s^int(x[j])
            j=j+2
        print s
    i=i+1
    
