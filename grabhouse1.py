n=input()
i=0
while i<n:
    k=input()
    if k==1 or k==2:
        print "1"
    else:
        val=k/2-1
        print (k*(k-1))/2+val
    i=i+1
