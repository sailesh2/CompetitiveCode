t=input()
i=0
while i<t:
    n=input()
    
    x=raw_input().split(' ')
    l=[]
    ans=[]
    arr=[]
    save=[0]*1000005
    k=0
    while k<n:
        arr.append(int(x[k]))
        k=k+1
    k=1
    while k<=n:
        if save[k]==1:
            k=k+1
            continue
        save[k]=1
        ctr=1
        s=k
        while k!=arr[s-1]:
            s=arr[s-1]
            save[s]=1
            ctr=ctr+1
        ans.append(ctr)
        k=k+1
#    k=0
#    while k<len(ans):
#        print ans[k]
#        k=k+1
    if len(ans)>1:
        a=ans[0]
        b=ans[1]
        if a>b:
            while 1:
                if a%b==0:
                    break
                temp=a
                a=b
                b=temp%b
            gcf=b
        else:
            while 1:
                if b%a==0:
                    break
                temp=b
                b=a
                a=temp%a
            gcf=a
        lcm=(ans[0]*ans[1])/gcf
        k=2
        while k<len(ans):
            sav=lcm
            a=lcm
            b=ans[k]
            if a>b:
                while 1:
                    if a%b==0:
                        break
                    temp=a
                    a=b
                    b=temp%b
                gcf=b
            else:
                while 1:
                    if b%a==0:
                        break
                    temp=b
                    b=a
                    a=temp%a
                gcf=a
            lcm=(sav*ans[k])/gcf
            k=k+1
    else:
        lcm=ans[0]
    print lcm%1000000007
    i=i+1
