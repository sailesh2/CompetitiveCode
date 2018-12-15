t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    a=int(x[0])
    gcd=a
    if n>1:
        b=int(x[1])
        if a>=b:
            while 1:
                if a%b==0:
                    break
                temp=a
                a=b
                b=temp%b
            gcd=b
        else:
            while 1:
                if b%a==0:
                    break
                temp=b
                b=a
                a=temp%a
            gcd=a
    j=2
    while j<n:
        a=gcd
        b=int(x[j])
        if a>=b:
            while 1:
                if a%b==0:
                    break
                temp=a
                a=b
                b=temp%b
            gcd=b
        else:
            while 1:
                if b%a==0:
                    break
                temp=b
                b=a
                a=temp%a
            gcd=a
        j=j+1
    if gcd==1:
        print "YEs"
    else:
        print "NO"
    i=i+1
