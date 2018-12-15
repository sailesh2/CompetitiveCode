import math
t=input()
i=0
while i<t:
    n=input()
    cnt=0
    while n>1:
        a=math.log(n,2)
        if a==int(a):
            n=n/2
        else:
            n=n-pow(2,int(a))
        cnt=1-cnt
    if cnt==0:
        print "Richard"
    else:
        print "Louise"
    i=i+1
