arr=[0]*100001
arr[1]=1
ans=[1]*100001
i=2
while i<=100000:
    n=i
    d = 2
    cnt=0
    while n > 1:
        while n % d == 0:
            if arr[n]!=0:
                cnt=1
                break
            ans[i]=((ans[i]%1000000007)*(d%1000000007))% 1000000007
            n /= d
        if cnt==1:
            break
        d = d + 1
        if d*d > n:
            if n > 1:
                ans[i]=((ans[i]%1000000007)*(n%1000000007))
            break
    arr[i]=ans[i]
    i=i+1
i=2
while i<=100000:
    ans[i]=((ans[i]%1000000007)*(ans[i-1]%1000000007))
    i=i+1
t=input()
i=0
while i<t:
    p=raw_input().split(' ')
    x=int(p[0])
    y=int(p[1])
    print ans[y]/ans[x-1]
    i=i+1
