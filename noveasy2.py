
arr=[0]*1000
arr[1]=4
p=[0]*1000
p[1]=3
i=2
while i<100:
    p[i]=(p[i-1]*3)%1000000007
    arr[i]=(arr[i-1]*2+arr[i-1]*3+p[i])%1000000007
    i=i+1
print arr
t=input()
i=0
while i<t:
    n=input()
    if n<100000:
        print arr[n]-p[n]
    else:
        k=100000-2
        j=k+1
        pr=p[j]*3
        s=(arr[j]*2+arr[k]*3+pr)%1000000007
        k=j
        j=s
        ctr=j+1
        while ctr<n:
            pr=pr*3
            s=(j*2+k*3+pr)%1000000007
            k=j
            j=s
            ctr=ctr+1
        print s
    i=i+1
