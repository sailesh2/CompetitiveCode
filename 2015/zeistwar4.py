import math
x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
arr=[]
i=0
while i<n:
    a=raw_input()
    j=0
    sm=0
    while j<m:
        sm=sm*2+int(a[j])
        j=j+1
    arr.append(sm)
    i=i+1
p=0
ctr=0
i=0
while i<n:
    j=i+1
    while j<n:
        if arr[i]|arr[j]>p:
            p=arr[i]|arr[j]
        j=j+1
    i=i+1
i=0
while i<n:
    j=i+1
    while j<n:
        if arr[i]|arr[j]==p:
            ctr=ctr+1
        j=j+1
    i=i+1
ctr2=0
while p>0:
    if p%2==1:
        ctr2+=1
    p=p/2
print ctr2
print ctr
