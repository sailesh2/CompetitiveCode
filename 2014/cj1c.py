import math
n=input()
i=0
while i<n:
    x=raw_input().split('/')
    p=int(x[0])
    q=int(x[1])
    ctr=0
    p1=p
    q1=q
    while 1:
        if q1%p1==0:
            break
        temp=q1
        q1=p1
        p1=temp%p1
    if math.log((float(q)/p1),2)!=int(math.log((float(q)/p1),2)) or p==0 or q%2!=0:
        print "Case #"+str(i+1)+": impossible"
    else:
        ctr=int(math.ceil(math.log(float(q)/p,2)))
        print "Case #"+str(i+1)+": "+str(ctr)
    i=i+1
