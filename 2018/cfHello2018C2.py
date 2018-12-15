x=raw_input().split(' ')
n=int(x[0])
l=int(x[1])
y=raw_input().split(' ')
i=0
c=[]
d=[]
p=1
while i<n:
    c.append([p/float(y[i]),i])
    d.append([p,long(y[i])])
    p=p*2
    i=i+1
c.sort()
c.reverse()
ans=0
while l!=0:
    i=0
    cnt=0
    cnt2=0
    while i<n:
        ind=c[i][1]
        p=d[ind][0]
        cost=d[ind][1]
        if p<=l:
            if cnt==1:
                if (l/p)*cost<mini:
                    tempL=l-(l/p)*p
                    ans=ans+(l/p)*cost
                    l=tempL
                else:
                    l=0
                    ans=ans+mini
            else:
                tempL=l-(l/p)*p
                ans=ans+(l/p)*cost
                l=tempL
            cnt2=1
            break
        else:
            if cnt==0:
                mini=cost
                cnt=1
            else:
                mini=min(mini,cost)
        
        i=i+1
        if cnt==1 and cnt2==0:
            l=0
            ans=ans+mini
print ans
