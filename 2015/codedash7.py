t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    l=int(x[0])
    b=int(x[1])
    p=l*b
    if l>=b:
        while 1:
            if l%b==0:
                gcd=b
                break
            temp=l
            l=b
            b=temp%b
    else:
        while 1:
            if b%l==0:
                gcd=l
                break
            temp=b
            b=l
            l=temp%l
    print p/(gcd*gcd)
    i=i+1
            
