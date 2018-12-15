x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
arr=raw_input().split(' ')
brr=raw_input().split(' ')
a=[]
b=[]
i=0
while i<n:
    a.append(int(arr[i]))
    b.append(int(brr[i]))
    i=i+1
i=0
while i<m:
    y=raw_input().split(' ')
    l=int(y[0])
    r=int(y[1])
    arr2=[]
    brr2=[]
    j=l-1
    k=0
    while j<r:
        arr2.append(a[j])
        brr2.append(b[j])
        k=k+1
        j=j+1
    arr2.sort()
    brr2.sort()
    j=0
    sm=0
    sm2=0
    while j<k:
        sm=sm+arr2[j]*brr2[j]
        sm2=sm2+arr2[j]*brr2[k-j-1]
        j=j+1
    if sm>=sm2:
        print sm
    else:
        print sm2
    i=i+1

        
