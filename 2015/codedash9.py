t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    a=raw_input().split(' ')
    b=raw_input().split(' ')
    arr=[]
    brr=[]
    j=0
    while j<n:
        arr.append(int(a[j]))
        brr.append(int(b[j]))
        j=j+1
    arr.sort()
    brr.sort()
    cnt=0
    j=0
    while j<n:
        if (arr[j]+brr[n-j-1])<k:
            cnt=1
            break
        j=j+1
    if cnt==0:
        print "YES"
    else:
        print "NO"
    i=i+1
