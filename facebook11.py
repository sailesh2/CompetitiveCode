t=input()
i=0
while i<t:
    s=raw_input()
    l=len(s)
    j=0
    arr=[]
    brr=[]
    while j<l:
        arr.append(int(s[j]))
        brr.append(int(s[j]))
        j=j+1
    j=0
    cnt=0
    while j<l:
        k=j+1
        maxi=0
        while k<l:
            if j==0:
                if arr[k]!=0 and arr[k]>arr[j]:
                    if arr[k]>=maxi:
                        maxi=arr[k]
                        cnt=1
                        save=k
            else:
                if arr[k]>arr[j]:
                    if arr[k]>=maxi:
                        maxi=arr[k]
                        cnt=1
                        save=k

            k=k+1
        if cnt==1:
            temp=arr[save]
            arr[save]=arr[j]
            arr[j]=temp
            break
        j=j+1
    j=0
    s1=''
    while j<l:
        s1=s1+str(arr[j])
        j=j+1
    
    j=0
    cnt=0
    while j<l:
        k=j+1
        mini=100
        while k<l:
            if j==0:
                if brr[k]!=0 and brr[k]<brr[j]:
                    if brr[k]<=mini:
                        mini=brr[k]
                        cnt=1
                        save=k
            else:
                if brr[k]<brr[j]:
                    if brr[k]<=mini:
                        mini=brr[k]
                        cnt=1
                        save=k

            k=k+1
        if cnt==1:
            temp=brr[save]
            brr[save]=brr[j]
            brr[j]=temp
            break
        j=j+1
    j=0
    s2=''
    while j<l:
        s2=s2+str(brr[j])
        j=j+1

    print "Case #"+str(i+1)+": "+s2,s1
    i=i+1   
