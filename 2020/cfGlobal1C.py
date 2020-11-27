import math

def gcd(a,b):
    print(a)
    if b==0:
        return a
    a=a%b
    return gcd(b,a)

q=int(input())

p=4
ctr=1
mp={}
while ctr<=5:
    i=1
    save=1
    maxi=0
    while i<p:
        g=gcd(i^p,i&p)
        if g>maxi:
            maxi=g
            save=i
        i=i+1
    mp[p-1]=save
    p=p*2
    ctr=ctr+1


i=0

while i<q:
    n=int(input())
    p=int(math.log(n,2))
    ans=pow(2,p+1)-1
    if ans==n:
        print(mp[n])
    else:
        print(ans)
    i=i+1
