import math
x=raw_input().split(' ')
k=int(x[0])
b=int(x[1])
n=int(x[2])
t=int(x[3])

if k==1:
    z=n*b+1
    a=float(z-t)/b
    if a<=0:
        print "0"
    else:
        print int(math.ceil(a))
else:
    p=pow(k,n)
    z=(p+b*(p-1)/(k-1))
    ans=(z*(k-1)+b)/(t*(k-1)+b)
    if ans==0:
        print "0"
    else:
        a=math.log(ans,k)
        if a<=0:
            print "0"
        else:
            print int(math.ceil(a))
