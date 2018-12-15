from decimal import *
x=raw_input().split(' ')
n=int(x[0])
l=int(x[1])
y=raw_input().split(' ')
i=0
c=[]
d=[]
p=1
while i<n:
    c.append([p/Decimal(y[i]),i])
    d.append([p,long(y[i])])
    p=p*2
    i=i+1

ans=0
while l!=0:
    i=0
    cnt=0
    while i<n:
        ind=c[i][1]
        p=d[ind][0]
        cost=d[ind][1]
        if p<=l:
            if cnt==0:
                tempL=l-(l/p)*p
                mini=(l/p)*cost
                cnt=1
            else:
                if (l/p)*cost<mini:
                    tempL=l-(l/p)*p
                    mini=(l/p)*cost
        else:
            if cnt==0:
                mini=cost
                tempL=0
                cnt=1
            else:
                if cost<mini:
                    mini=cost
                    tempL=0
        i=i+1
    l=tempL
    ans=ans+mini

print ans
