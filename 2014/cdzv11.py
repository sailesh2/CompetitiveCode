t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    if n==1:
        print int(x[0])
    elif n==0:
        print "0"
    else:
        a=int(x[0])
        b=int(x[1])
        if a>b:
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
        j=2
        while j<n:
            a=gcd
            b=int(x[j])
            if a>b:
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
            j=j+1
        print gcd*n
    i=i+1

            
        
