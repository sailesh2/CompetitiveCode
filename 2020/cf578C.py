import math
def gcd(a,b):
    
   if b==0:
      return a
   a=a%b
   return gcd(b,a)

def lcm(a,b):
    return (a*b)//gcd(a,b)

def ceil(a,b):
    if a%b == 0:
        return a//b
    return a//b +1


z=input().split(' ')
i=0
n=int(z[0])
m=int(z[1])
t=int(z[2])

l=lcm(n,m)
                
while i<t:
    x=input().split(' ')
    sx=int(x[0])
    sy=int(x[1])
    ex=int(x[2])
    ey=int(x[3])

    v1=0
    if sx==1:
        v1=m*sy
    else:
        v1=n*sy

    v2=0
    if ex==1:
        v2=m*ey
    else:
        v2=n*ey

    if ceil(v1,l) == ceil(v2,l):
        print("YES")
    else:
        print("NO")
    i=i+1
    
