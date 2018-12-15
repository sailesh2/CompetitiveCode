t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    num=int(x[0])
    m=int(x[1])
    s=1
    j=2
    while j*j<=num:
        if num%j==0:
            s=s+j
            s=s+num/j
        if j*j==num:
            s=s-j
        j=j+1
    s=s%m
    print s
    ctr=1
    j=2
    while j*j<=s:
        if s%j==0:
            ctr=ctr+2
        if j*j==s:
            ctr=ctr-1
        j=j+1
    print ctr
    print "Case #"+str(i+1)+" :",
    if pow(5*(ctr**2)+4,0.5)==int(pow(5*(ctr**2)+4,0.5)):
        print "YES."
    elif pow(5*(ctr**2)-4,0.5)==int(pow(5*(ctr**2)-4,0.5)):
        print "YES."
    else:
        print "NO."
    i=i+1
