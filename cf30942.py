import math
x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
fib=[1]
a=0
i=1
while i<=n:
    fib.append(a+fib[i-1])
    a=fib[i-1]
    i=i+1
ans=[]
i=n-1
ctr=1
while i>=1:
    if k<=fib[i]:
        ans.append(ctr)
        ctr=ctr+1
        i=i-1
    else:
        ans.append(ctr+1)
        ans.append(ctr)
        ctr=ctr+2
        k=k-fib[i]
        i=i-2
if len(ans)<n:
    ans.append(n)
i=0
while i<len(ans):
    print ans[i],
    i=i+1
