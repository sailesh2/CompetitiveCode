n=input()
if n==3:
    print "1"
else:
    a=3+2*(n-4)
    val1=(a*(a+1))/2
    a=a-1
    a=a/2
    val2=(a*(a+1))
    print val1-val2
