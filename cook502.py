t=input()
i=0
while i<t:
    n=input()
    arr=[]
    j=0
    while j<n:
        x=raw_input()
        arr.append(x)
        j=j+1
    sm=0
    has=[0]*n
    j=n-1
    while j>=0:
        ctr=0
        cnt=0
        k=n-1
        while k>=0:
            if arr[j][k]=='#':
                has[k]=1
                cnt=1
            else:
                if cnt==0 and has[k]==0:
                    ctr=ctr+1
            k=k-1
        sm=sm+ctr
        j=j-1
    print sm
    i=i+1
