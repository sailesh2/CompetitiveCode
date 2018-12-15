x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
y=raw_input().split(' ')
a=[]
s=0
i=0
p=1
prr=[]
while i<n+1:
    a.append(int(y[i]))
    prr.append(p)
    s=s+p*a[i]
    p=p*2
    i=i+1

i=0
ctr=0
while i<n+1:
    d=s-prr[i]*a[i]
    if d%prr[i]==0:
        b=d/prr[i]
        if abs(b)<=k:
            ctr=ctr+1
            if i==n and abs(b)==0:
                ctr=ctr-1
    
    i=i+1
print ctr
