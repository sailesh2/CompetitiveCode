t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    arr=[]
    j=0
    while j<n:
        arr.append(int(x[j]))
        j=j+1
    sm=0
    m=n
    j=0
    while j<n-2:
        k=1
        save=-1
        mini=1000000000000
        while k<m-1:
            if arr[k]*arr[k-1]+arr[k]*arr[k+1]+arr[k-1]*arr[k+1]<mini:
                mini=arr[k]*arr[k-1]+arr[k]*arr[k+1]+arr[k-1]*arr[k+1]
                save=k
            k=k+1
        if save!=-1:
            sm=sm+mini
            arr.remove(arr[save])
            m=m-1
        j=j+1
    print sm
    i=i+1
