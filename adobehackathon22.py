n=input()
x=raw_input().split(' ')

arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
i=0
fac=[0]*10000000
while i<n:
    val=arr[i]
    j=1
    while j*j<=val:
        if val%j==0:
            if val/j==j:
                fac[j]=fac[j]+1
            else:
                fac[j]=fac[j]+1
                fac[val/j]=fac[val/j]+1
        j=j+1
    i=i+1
i=0
while i<n:
    print (pow(2,fac[arr[i]],1000000007)-1)%1000000007,
    i=i+1
