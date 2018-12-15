x=input()
y=input()
z=input()
a=x
b=y
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
k=1
while 1:
    z=z*k
    if z%gcd==0:
        x=x/gcd
        y=y/gcd
        z=z/gcd
        a=x
        b=y
        s1=1
        s2=0
        t1=0
        t2=1
        if a>=b:
            while 1:
                if a%b==0:
                    break
                r=a%b
                q=a/b
                a=b
                b=r

                temp=s2
                s2=s1-q*s2
                s1=s2

                temp=t2
                t2=t1-q*t2
                t1=t2
            print z*s1+z*t1
        else:
            while 1:
                if b%a==0:
                    break
                r=b%a
                q=b/a
                b=a
                a=r

                temp=s2
                s2=s1-q*s2
                s1=s2

                temp=t2
                t2=t1-q*t2
                t1=t2
            print z,s1,t1
            print z*s1+z*t1
        break
    k=k+1
