t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    c=int(x[2])
    if a>=b:
        a1=a
        while 1:
            if a%b==0:
                break
            temp=a
            a=b
            b=temp%b
        if c%b==0 and c<=a1:
            print "YES"
        else:
            print "NO"
    else:
        b1=b
        while 1:
            if b%a==0:
                break
            temp=b
            b=a
            a=temp%a
        if c%a==0 and c<b1:
            print "YES"
        else:
            print "NO"
    i=i+1
