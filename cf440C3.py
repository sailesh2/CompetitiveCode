def isPrime(x):
    if (3**(x-1))%x==0 or x%3==0:
        if x%3==0:
            return x==3
        else:
            return True
    else:
        return False
p=[0,1,1,1]
i=4
while i<=3001:
    j=2
    cnt=1
    while j<i:
        if i%j==0:
            cnt=0
            break
        j=j+1
    p.append(cnt)
    i=i+1
q=int(raw_input())
i=0
while i<q:
    n=int(raw_input())
    j=1
    save=-1
    if n<3000:
        isp=p[n]
    else:
        isp=isPrime(n)
    if isp:
        save=-1
    else:
        save=1
    while j<=min(3000,n):
        if p[j]==0 and n%j==0:
            save=n/j
            break
        j=j+1
        
    print save
    i=i+1
