import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    m=int(x[0])
    n=int(x[1])
    if math.log(m)==0:
        m1=0
    else:
        m1=float(m)/math.log(m)
    if math.log(n)==0:
        n1=0
    else:
        n1=float(n)/math.log(n)
    if (int(n1)-int(m1))%2==0:
        print "YES"
    else:
        print "NO"
    i=i+1
