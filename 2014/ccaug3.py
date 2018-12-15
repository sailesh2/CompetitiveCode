t=input()
i=0
while i<t:
    n=input()
    j=0
    p=1
    arr=[0]*101
    while j<n:
        x=raw_input().split(' ')
        k=0
        while k<len(x):
            arr[int(x[k])]=arr[int(x[k])]+1
            k=k+1
        p=p*len(x)
        j=j+1
    k=0
    while k<101:
        if arr[k]>1:
            p=p-(arr[k]*(arr[k]-1))/2
        k=k+1
    print p%1000000007
    i=i+1
