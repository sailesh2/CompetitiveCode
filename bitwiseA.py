n=input()
if n==1:
    print "1"
else:
    print (((n*(n+1))%1000000007)*pow(2,n-2,1000000007))%1000000007
