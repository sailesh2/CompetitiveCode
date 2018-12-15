n=input()
arr=[]
brr=[]
i=0
while i<n:
    x=raw_input().split(' ')
    arr.append(int(x[0]))
    brr.append(float(x[1]))
    i=i+1
i=0
while i<n:
    j=i+1
    while j<n:
        if brr[j]<brr[i]:
            temp=brr[j]
            brr[j]=brr[i]
            brr[i]=temp

            temp=arr[j]
            arr[j]=arr[i]
            arr[i]=temp
        j=j+1
    i=i+1
sm=0
p=1
i=0
while i<n:
    j=0
    sumi=0
    pr=1
    while j<i:
        sumi=sumi+arr[j]
        pr=pr*brr[j]
        j=j+1
    sumi=sumi+arr[i]
    pr=pr*(1-brr[i])
    p=p*brr[i]
    sm=sm+sumi*pr
    i=i+1
print sm+(sumi*p)
