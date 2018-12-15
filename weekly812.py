import math
t=input()
i=0
while i<t:
    n=input()
    cnt=0
    a=int(math.floor(math.log(n,2)))
    a=math.pow(2,a)
    ctr=0
    cnt=0
    ctr2=2
    while 1:
        while 1:
            if n>=a+ctr and n<=a+ctr2:
                break
            ctr=ctr2
            ctr2=ctr2*2
        if n-a+ctr==0:
            cnt=int(math.floor(math.log(n,2)))+cnt
            if cnt%2!=0:
                print "Louise"
            else:
                print "Richard"
            break
        elif n-a+ctr==1:
            if cnt==0:
                print "Louise"
            else:
                print "Richard"
            break
        elif n-a+ctr==2:
            if cnt==1:
                print "Louise"
            else:
                print "Richard"
            break
        else:
            n=n-a
            a=ctr
            ctr=0
            ctr2=2
        cnt=1-cnt
    i=i+1
