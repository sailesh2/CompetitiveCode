t=input()
i=0
while i<t:
    xa=raw_input().split(' ')
    n=int(xa[0])
    q=int(xa[1])
    y=raw_input().split(' ')
    j=0
    arr=[]
    while j<n:
        arr.append(int(y[j]))
        if j!=0:
            arr[j]=arr[j]+arr[j-1]
        j=j+1
    k=0
    z=raw_input().split(' ')
    while k<q:
        x=int(z[k])
        sm=0
        j=0
        while j<n:
            p1=int(pow(x,float(1)/(j+1)))
            if p1==1:
                if x<=n:
                    if j==0:
                        sm=sm+(p1%1000000007*arr[x-1]%1000000007)%1000000007
                    else:
                        sm=sm+(p1%1000000007*(arr[x-1]-arr[j-1])%1000000007)%1000000007
                else:
                    if j==0:
                        sm=sm+(p1%1000000007*arr[n-1]%1000000007)%1000000007
                    else:
                        sm=sm+(p1%1000000007*(arr[n-1]-arr[j-1])%1000000007)%1000000007
                break
            #p=pow(p1,(j+1))
            p=1
            pow2=p1
            num=j+1
            s=bin(j+1)
            start=len(s)-1
            while start>=2:
                if s[start]=='1':
                    p=p*pow2
                pow2=pow2*pow2
                start=start-1
            if p==x:
                if j==0:
                    sm=sm+(p1%1000000007*arr[j]%1000000007)%1000000007
                else:
                    sm=sm+(p1%1000000007*(arr[j]-arr[j-1])%1000000007)%1000000007
            else:
                power=p1
                power_save=p
                save=j
                ctr=1
                save1=save
                while save+ctr<n:
                    if p*power<=x:
                        save1=save+ctr
                        ctr=ctr*2
                        power_save=p*power
                        power=power*power
                    else:
                        if save+ctr==save1+1:
                            break
                        save=save1
                        ctr=1
                        p=power_save
                        power=p1
                
                if j==0:
                    sm=sm+(p1%1000000007*arr[save1]%1000000007)%1000000007
                else:
                    sm=sm+(p1%1000000007*(arr[save1]-arr[j-1])%1000000007)%1000000007
                j=save1
            j=j+1
        print sm%1000000007,
        k=k+1
    print
    i=i+1
