t=input()
i=0
arr=[]
while i<t:
    x=raw_input()
    x=x.split(' ')
    n=int(x[0])
    m=int(x[1])
    p=1
    c=1
    cnt=1
    if n<=m:
        while cnt<=(n-1):
            p=(p%1000000007)*((m-1+cnt)%1000000007)
            c=c*cnt
            cnt=cnt+1
    else:
        while cnt<=(m-1):
            p=(p%1000000007)*((n-1+cnt)%1000000007)
            c=c*cnt
            cnt=cnt+1
    arr.append((p/c)%1000000007)
    i=i+1
i=0
while i<t:
    print arr[i],
    i=i+1
