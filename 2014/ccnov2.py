t=input()
i=0
while i<t:
    s=raw_input()
    cnt=0
    j=0
    lt=len(s)
    k=len(s)-1
    while j<=k:
        if s[j]!=s[k]:
            cnt=1
            a=j+1
            b=k-1
            break
        else:
            j=j+1
            k=k-1
    if cnt==0:
        print "YES"
    else:
        cnt2=0
        while a<=k:
            if s[a]!=s[k]:
                cnt2=1
                break
            else:
                a=a+1
                k=k-1
        cnt3=0
        while j<=b:
            if s[j]!=s[b]:
                cnt3=1
                break
            else:
                j=j+1
                b=b-1
        if  cnt2==0 or cnt3==0:
            print "YES"
        else:
            print "NO"
    i=i+1



