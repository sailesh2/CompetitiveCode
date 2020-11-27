x=input().split(' ')
n=int(x[0])

m=int(x[1])

factors=[]
factorCount = {}

ctr=0
while m%2==0:
    m=m//2
    ctr=ctr+1

if ctr>0:
    factors.append(2)
    factorCount[2]=ctr

i=3
while i*i<=m:
    ctr=0
    while m%i==0:
        m=m//i
        ctr=ctr+1
    if ctr>0:
        factors.append(i)
        factorCount[i]=ctr
    i=i+2

if m>1:
    factors.append(m)
    factorCount[m]=1

i=0
mini=0
while i<len(factors):
    f=factors[i]
    fc=factorCount[f]
    ctr=0
    tf=f
    while n//tf>0:
        ctr=ctr+n//tf
        tf=tf*f

    if i==0:
        mini=ctr//fc
    else:
        mini=min(mini,ctr//fc)
    i=i+1

print(mini)
