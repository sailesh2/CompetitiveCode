t=input()
i=0
while i<t:
    orig=raw_input()
    co=raw_input()
    n=len(orig)
    m=len(co)
    maxi=0
    j=0
    while j<m:
        k=0
        while k<n:
            if orig[k]==co[j]:
                l=j
                l2=k
                while l<m and l2<n:
                    if orig[l2]!=co[l]:
                        break
                    l+=1
                    l2+=1
                if l-j>maxi:
                    maxi=l-j
            k=k+1
        j=j+1
    maxi2=0
    p=0
    while p<m:
        j=p
        ctr=0
        save=0
        save2=j
        while j<m:
            k=save
            cnt2=0
            while k<n:
                if co[j]==orig[k]:
                    if k-save==j-save2:
                        save=k
                        save2=j
                        ctr+=1
                        cnt2=1
                if cnt2==1:
                    break
                k=k+1
            j=j+1
        if ctr>maxi2:
            maxi2=ctr
        p=p+1
    if maxi2>maxi:
        maxi=maxi2
    print m-maxi
    i=i+1
