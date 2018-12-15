t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    j=0
    arr=[]
    while j<n:
        y=raw_input()
        s=0
        k=0
        while k<m:
            if y[k]=='1':
                s=s*2+1
            k=k+1
        arr.append(s)
        j=j+1
    cnt=1
    p=1
    k=0
    while k<m:
        cnt=0
        sav=[0]*2000
        j=0
        while j<n:
            l=arr[j]%p
            f=arr[j]/(p*2)
            if sav[l*p+f]==1:
                cnt=1
                break
            sav[l*p+f]=1
            j=j+1
        if cnt==0:
            print "Yes"
            break
        p=p*2
        k=k+1
    if cnt==1:
        print "No"
    i=i+1
