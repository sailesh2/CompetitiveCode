t=input()
i=0
while i<t:
    n=input()
    if n%2==0:
        print (pow(2,n/2,1000000007)-1)%1000000007
    else:
        print "0"
    i=i+1
