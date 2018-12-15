t=input()
i=0
while i<t:
    n=input()
    if(n==1):
        print "0"
    elif (n==2):
        print "4"
    else:
        b=2
        m=1000000007
        val2=pow(3,n-2,m)
        val21=pow(3,n-2,b*m)
        val22=pow(2,n-1,m)
        val=((6*val2)%m+(((val21-1)%(b*m))/2)%m)%m
        val=(val-val22%m)%m
        print val
    i=i+1
