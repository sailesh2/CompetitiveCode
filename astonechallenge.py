import math
t=input()
i=0
while i<t:
    n=input()
    if n==1:
        print 1
    else:
        dif=n-2**int(math.log(n,2))+1
        if dif%2==0:
            print 1
        else:
            print 2**int(math.log(n,2))-1
    i=i+1
