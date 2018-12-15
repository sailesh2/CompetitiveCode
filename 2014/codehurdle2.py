import math
t=input()
dif=0
dif2=0
i=0
while i<t:
    n=input()
    if n==0:
        a=-1
        b=-1
    else:
        m=n
        lt=0
        while m>0:
            m=m/2
            lt=lt+1
        m=n
        arr=[0]*lt
        arra=[0]*lt
        arrb=[0]*lt
        l=0
        while m>0:
            arr[lt-1-l]=m%2
            arra[lt-1-l]=m%2
            arrb[lt-1-l]=m%2
            l=l+1
            m=m/2
        j=l-1
        cnt=0
        ctr=0
        savek=0
        suc=0
        while j>=0:
            if arr[j]==1:
                ctr=ctr+1
            if arr[j]==0:
                cnt=1
            if cnt==1 and arr[j]==1:
                suc=1
                ctr=ctr+1
                savek=j
                break
            j=j-1
        if suc==1:
            cnt2=0
            arra[savek]=0
            savek=savek+1
            while savek<l:
                if cnt2<ctr:
                    arra[savek]=1
                else:
                    arra[savek]=0
                cnt2=cnt2+1
                savek=savek+1
            p=1
            a=0
            j=l-1
            while j>=0:
                a=a+p*arra[j]
                p=p*2
                j=j-1
        else:
            a=-1
        j=l-1
        cnt=0
        ctr=0
        save=0
        suc=0
        while j>=0:
            if arr[j]==1:
                ctr=ctr+1
            if arr[j]==1:
                cnt=1
            if cnt==1 and arr[j]==0:
                suc=1
                ctr=ctr-1
                save=j
                break
            j=j-1
        if suc==1:
            arrb[save]=1
            j=save+1
            lb=l
        else:
            arrb.append(0)
            arrb[0]=1
            ctr=ctr-1
            lb=l+1
            j=1
        while j<l:
            arrb[j]=0
            j=j+1
        cnt2=0
        j=lb-1
        while j>=0:
            if cnt2==ctr:
                break
            arrb[j]=1
            cnt2=cnt2+1
            j=j-1
      
        p=1
        b=0
        j=lb-1
        while j>=0:
            b=b+p*arrb[j]
            p=p*2
            j=j-1
    dif=dif+b-a
    if n*n==a*b:
        dif2=dif2+1
    i=i+1
print '%.6f' %(float(dif2)/t),'%.6f' %(float(dif)/t)
