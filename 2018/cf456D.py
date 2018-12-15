x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
y=raw_input().split(' ')
mod=1000000007
arr=[]
i=0
while i<n:
    arr.append(int(y[i]))
    i=i+1

y=raw_input().split(' ')
brr=[]
i=0
while i<n:
    brr.append(int(y[i]))
    i=i+1


i=0
p=1
sm=0
pm=pow(m,mod-2,mod)
pm2=pow((m*m),mod-2,mod)
while i<n:
    if arr[i]==0 and brr[i]==0:
        sm=(sm+((((m*(m-1))/2)%mod * pm2)%mod * p)%mod)%mod
        p=(p*m*pm2)%mod
    elif arr[i]==0:
        sm=(sm+(((m-brr[i])%mod * pm)%mod * p)%mod)%mod
        p=(p*1*pm)%mod
    elif brr[i]==0:
        sm=(sm+(((arr[i]-1)%mod * pm)%mod * p)%mod)%mod
        p=(p*1*pm)%mod
    else:
        if arr[i]<brr[i]:
            break
        elif arr[i]>brr[i]:
            sm=(sm + p)%mod
            break
    i=i+1
print sm
