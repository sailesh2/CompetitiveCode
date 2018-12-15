n=input()
has=[0]*1001
maxi=0
i=0
while i<n:
    a=input()
    if a>=maxi:
        maxi=a
    has[a]=1
    i=i+1
p1=input()
p=p1
ctr=0
while p>=1:
    if has[p]==0:
        ctr=ctr+1
    else:
        break
    p=p-1
ans=ctr
ctr=0
p=p1
while p<=maxi:
    if has[p]==0:
        ctr=ctr+1
    else:
        break
    p=p+1
print ans,ctr
print ans*ctr-1
