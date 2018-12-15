import math
s=raw_input()
n=int(s)
x=raw_input().split(' ')
l=int(x[0])
r=int(x[1])
d=int(math.floor(math.log(n,10)))+1
p=pow(10,d-1)
cnt=0
ctr=0
while p!=0:
    a=n/p
    b=n%p
    ctr=ctr+1
    if a%l==0 and b%r==0 and a!=0 and b!=0:
        cnt=1
        print "YES"
        k=ctr
        p1=1
        while k<d:
            if s[k]=='0':
                p1=p1*10
            else:
                break
            k=k+1
        print a*p1
        print b
        break
    p=p/10
if cnt==0:
    print "NO"
