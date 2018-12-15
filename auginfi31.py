t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    x1=int(x[0])
    y1=int(x[1])
    x2=int(x[2])
    y2=int(x[3])
    a=int(x[4])
    b=int(x[5])
    maxix=0
    minix=0
    if x1>=x2:
        maxix=x1
        minix=x2
    else:
        maxix=x2
        minix=x1
    maxiy=0
    miniy=0
    if y1>=y2:
        maxiy=y1
        miniy=y2
    else:
        maxiy=y2
        miniy=y1
    if x1==x2:
        a1=1
        b1=0
        c1=-1*x1
    else:
        slope=float(y2-y1)/(x2-x1)
        a1=slope
        b1=-1
        c1=y1-a1*x1
    if c1*(a1*a+b1*b+c1)>0:
        print "YES"
    elif c1*(a1*a+b1*b+c1)==0:
        if c1==0 and (a1*a+b1*b+c1)==0:
            if abs(a)<=abs(minix) and abs(b)<=abs(miniy):
                print "YES"
            else:
                print "NO"
        else:
            if c1==0:
                print "YES"
            else:
                if a<=maxix and a>=minix and b<=maxiy and b>=miniy:
                    print "NO"
                else:
                    print "YES"
    else:
        if x2==x1:
            a1=1
            b1=0
            c1=-1*x1
        else:
            slope=float(y2-y1)/(x2-x1)
            a1=slope
            b1=-1
            c1=y1-a1*x1
        if a==0:
            a2=1
            b2=0
            c2=0
        else:
            slope=float(b)/(a)
            a2=slope
            b2=-1
            c2=0
        xans=float(b1*c2-b2*c1)/(b2*a1-b1*a2)
        yans=float(a1*c2-a2*c1)/(a2*b1-a1*b2)

        if xans>=minix and xans<=maxix and yans<=maxiy and yans>=miniy:
            print"NO"
        else:
            print "YES"
    i=i+1
