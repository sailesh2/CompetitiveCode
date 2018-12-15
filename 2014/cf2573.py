x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
if k>n-1+m-1:
    print "-1"
else:
    if k+1<=n:
        minn=(n/(k+1))*m
    else:
        minn=m/(k+1-(n-1))
    if k+1<=m:
        minm=(m/(k+1))*n
    else:
        minm=n/(k+1-(m-1))
    print max(minn,minm)
