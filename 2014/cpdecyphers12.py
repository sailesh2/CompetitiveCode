t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    if float(n)/m==n/m:
        print "TCET Rocks!"
    else:
        a=n
        b=m
        if a>=b:
            while 1:
                if a%b==0:
                    gcd=b
                    break
                temp=a
                a=b
                b=temp%b
        else:
            while 1:
                if b%a==0:
                    gcd=a
                    break
                temp=b
                b=a
                a=temp%a
        m=m/gcd
        if m%2==0 or m%5==0:
            print "TCET Rocks!"
        else:
            print "It's Ok!"
    i=i+1
