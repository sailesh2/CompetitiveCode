import math
x=raw_input().split(' ')

n=int(x[0])
w=int(x[1])
b=int(x[2])

if(w==b):
    print "1/1"
else:

    w1=w
    b1=b
    if w>=b:
        while 1:
            if w%b==0:
                gcd=b
                break
            temp=w
            w=b
            b=temp%b
    else:
        while 1:
            if b%w==0:
                gcd=w
                break
            temp=b
            b=w
            w=temp%w
    lcm=(w1*b1)/gcd
    step=n/lcm

    fn=lcm*step
    mini=min(n-fn,min(w1,b1)-1)
    p=(step+(step)*(min(w1,b1)-1)+mini)
    q=(n)

    w=p
    b=q

    if w>=b:
        while 1:
            if w%b==0:
                gcd=b
                break
            temp=w
            w=b
            b=temp%b
    else:
        while 1:
            if b%w==0:
                gcd=w
                break
            temp=b
            b=w
            w=temp%w
    
    print str(p/gcd)+"/"+str(q/gcd)
