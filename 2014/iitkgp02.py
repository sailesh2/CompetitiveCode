t=input()
i=0
while i<t:
    arr=[-1]*10
    n=input()
    x=raw_input().split(' ')
    j=0
    maci=1
    while j<n:
        if arr[int(x[j])]==-1:
            arr[int(x[j])]=j
        else:
            if j-arr[int(x[j])]+1>maci:
                maci=j-arr[int(x[j])]+1
        j=j+1
    print maci
    i=i+1
