x=input().split(' ')
n=int(x[0])
m=int(x[1])

if m==0:
    print(n,n)
else:
    i=1
    ans=n
    while i<=n:
        if int((i*(i-1))/2) >= m:
            ans=i
            break
        i=i+1
    print(max(0,n-2*m),n-ans)
