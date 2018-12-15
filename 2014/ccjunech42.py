import math
t=input()
i=0
while i<t:
    xa=raw_input().split(' ')
    n=int(xa[0])
    q=int(xa[1])
    y=raw_input().split(' ')
    j=0
    arr=[]
    while j<n:
        arr.append(int(y[j]))
        if j!=0:
            arr[j]=arr[j]+arr[j-1]
        j=j+1
    k=0
    z=raw_input().split(' ')
    while k<q:
        x=int(z[k])
        sm=0
        j=0
        while j<n:
            p1=pow(x,float(1)/(j+1))
            if int(p1)==1:
                if x<=n:
                    if j==0:
                        sm=sm+(int(p1)%1000000007*arr[x-1]%1000000007)%1000000007
                    else:
                        sm=sm+(int(p1)%1000000007*(arr[x-1]-arr[j-1])%1000000007)%1000000007
                else:
                    if j==0:
                        sm=sm+(int(p1)%1000000007*arr[n-1]%1000000007)%1000000007
                    else:
                        sm=sm+(int(p1)%1000000007*(arr[n-1]-arr[j-1])%1000000007)%1000000007
                break
            if p1==int(p1):
                if j==0:
                    sm=sm+(int(p1)%1000000007*arr[j]%1000000007)%1000000007
                else:
                    sm=sm+(int(p1)%1000000007*(arr[j]-arr[j-1])%1000000007)%1000000007
            else:
                save1=int(math.log(x,int(p1)))-1
                if j==0:
                    sm=sm+(int(p1)%1000000007*arr[save1]%1000000007)%1000000007
                else:
                    sm=sm+(int(p1)%1000000007*(arr[save1]-arr[j-1])%1000000007)%1000000007
                j=save1
            j=j+1
        print sm%1000000007,
        k=k+1
    print
    i=i+1
