t=input()
i=0
while i<t:
    arr=[]
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    y=raw_input().split(' ')
    j=0
    ans=0
    while j<n:
        arr.append(int(y[j]))
        ans=ans+(int(y[j]))
        j=j+1
    if n==1 or k==1:
        print ans%1000000007
    else:
        nfac=1
        kfac=1
        nkfac=1
        j=1
        while j<=n:
            nfac=nfac*j
            if j==k:
                kfac=nfac
            if j==n-k:
                nkfac=nfac
            j=j+1
##        print nfac,kfac,nkfac
        nfac=nfac/n
        kfac=kfac/k
        arr.sort()
        sm=(nfac/(kfac*nkfac))
        if k>1:
            kfac=kfac/(k-1);
        sm1=0
        j=1
        ans=arr[0]*(nfac/(kfac*nkfac))
##        print ans
        while j<n:
            nfac=nfac/(n-j)
            if j==1:
                sm1=nfac/nkfac
            else:
                sm1=sm1+nfac/nkfac
            ans=ans+arr[j]*(sm-sm1/kfac)
            if n-k-j==0:
                break
            nkfac=nkfac/(n-k-(j-1))
            j=j+1
        print ans%1000000007
    i=i+1
