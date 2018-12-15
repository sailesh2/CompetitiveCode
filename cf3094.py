import math
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
arr=[0]
i=n
while i>=1:
    arr.append(i)
    i=i-1
brr=[]
while k>1:
    s=int(math.ceil(math.log(k,2)))
    brr.append(s)
    print s
    a=pow(2,s-1)
    k=k-a
i=len(brr)-1
while i>=0:
    ind=brr[i]
    temp=arr[ind]
    arr[ind]=arr[ind+1]
    arr[ind+1]=temp
    i=i-1
i=n
while i>=1:
    print arr[i],
    i=i-1
    
