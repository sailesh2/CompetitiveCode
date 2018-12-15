t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    has=[0]*1001
    arr=[]
    brr=[]
    j=0
    while j<n:
        arr.append(int(x[j]))
        has[arr[j]]+=1
        j=j+1
    j=0
    while j<=1000:
        if has[j]!=0:
            brr.append(has[j])
        j=j+1
    brr.sort()
    #print brr
    k=len(brr)
    cnt=0
    j=0
    while j<k-1:
        if n<=0:
            cnt=1
            break
        if j!=0:
            n=n-(brr[j]-brr[j-1])*(k-j)
        else:
            n=n-brr[j]*(k-j)
        j=j+1
    if cnt==1:
        print "can do"
    elif cnt==0 and n<=0:
        print "can do"
    else:
        if k-1!=0:
            brr[k-1]=brr[k-1]-brr[k-2]
        if n==1 and brr[k-1]>0:
            print "can do"
        else:
            print "bad luck"
    i=i+1
    
