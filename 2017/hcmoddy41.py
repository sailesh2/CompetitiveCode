x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])

maxis=-1000000000000000
s=0
s1=0
ctr=0
brr=[]
i=0
y=raw_input().split(' ')
while i<n:
    arr=int(y[i])
    if ctr>0:
        s1=s+arr-(k*(i-brr[ctr-1]-1)*(i-brr[ctr-1]-1))
    else:
        s1=s+arr
    s=s1
    maxis=max(maxis,s)
    brr.append(i)
    ctr=ctr+1
    i=i+1
print maxis
