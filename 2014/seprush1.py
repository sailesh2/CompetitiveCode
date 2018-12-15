n=1000
a=[0]*1005
a[0]=1
a[1]=1
i=2
while i<=1000:
    if i%2!=0:
        j=i*i
        while j<=1000:
            a[j]=1
            j=j+i
    i=i+1
arr=[0]
ctr=0
i=1
while i<=1000:
    if i==2:
        ctr=ctr+1
    if i%2!=0:
        if a[i]==0:
            ctr=ctr+1
    arr.append(ctr)
    i=i+1
print arr
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    l=int(x[0])
    r=int(x[1])
    print (r-l+1)-(arr[r]-arr[l-1])
    i=i+1
