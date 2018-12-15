
def fun(n,l):
    global lf
    global rt
    if n==l-1:
        if rt[n]>lf[n-1]:
            m=rt[n]
        else:
            m=lf[n-1]
        if lf[n]<=m:
            return lf[n]
        else:
            return m
    a=fun(n+1,l)

    if rt[n]>lf[n-1]:
            m=rt[n]
    else:
        m=lf[n-1]
    if a<=m:
        return a
    else:
        return m
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    y=raw_input().split(' ')
    mice=[]
    j=0
    while j<n:
        mice.append(int(y[j]))
        j=j+1
    hole=[]
    z=raw_input().split(' ')
    j=0
    while j<m:
        hole.append(int(z[j]))
        j=j+1
    mice.sort()
    hole.sort()
    maxi=0
    k=0
    cnt=0
    j=0
    while j<n:
        mini=1000000000
        while m-k-1>=n-j-1:
            if abs(mice[j]-hole[k])<=mini:
                mini=abs(mice[j]-hole[k])
            else:
                break
            k=k+1
        if cnt==0 and m-k-1<n-j-1:
            if mini>=maxi:
                mini=maxi
            maxsave=maxi
            cnt=1
            save=j
            save1=k
        if mini>=maxi:
            maxi=mini
        j=j+1
    if cnt==1:
        if save1-2>=0:
            maxi2=0
            l=0
            arr=[]
            while save+l<n:
                arr.append([abs(mice[save+l]-hole[save1+l-2]),abs(mice[save+l]-hole[save1+l-1])])
                l=l+1
            print arr
            maxil=0
            maxir=0
            global lf
            global rt
            lf=[0]*10000
            rt=[0]*10000
            j=l-1
            while j>=0:
                if arr[j][1]>=maxir:
                    maxir=arr[j][1]
                rt[j]=maxir
                j=j-1
            j=0
            while j<l:
                if arr[j][0]>=maxil:
                    maxil=arr[j][0]
                lf[j]=maxil
                j=j+1
            if l==1:
                if lf[0]<=rt[0]:
                    maxi2=lf[0]
                else:
                    maxi2=rt[0]
            else:
                maxi2=fun(1,l)
                if rt[0]<=maxi2:
                    maxi2=rt[0]
            if maxsave>=maxi2:
                maxi2=maxsave
            if maxi2<=maxi:
                maxi=maxi2
    print maxi
    i=i+1
