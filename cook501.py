t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    maxi=-1
    j=0
    k=1
    while k<n:
        a=int(x[j])
        b=int(x[k])
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
        if gcd==1:
            if k-j>=maxi:
                maxi=k-j+1
        if gcd>1:
            j=j+1
            while j<k:
                a=int(x[j])
                b=int(x[k])
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
                if gcd==1:
                    break
                j=j+1
        k=k+1
    print maxi
    i=i+1
