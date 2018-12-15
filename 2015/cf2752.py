x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])

arr=[]
has=[0]*100001
i=1
j=1+k
l=0
while l<n and i<j:
    has[i]=1
    has[j]=1
    arr.append(i)
    arr.append(j)
    i=i+1
    j=j-1
    l=l+2
i=1
while l<n:
    while has[i]==1:
        i=i+1
    has[i]=1
    arr.append(i)
    l=l+1
i=0
while i<n:
    print arr[i],
    i=i+1
