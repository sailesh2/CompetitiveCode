n=input()
x=raw_input().split(' ')
arr=[]
sm=[]
i=0
while i<n:
    arr.append(int(x[i]))
    if i==0:
        sm.append(arr[i])
    else:
        sm.append(sm[i-1]+arr[i])
    i=i+1
i=0
f=[]
fsm=[]
brr=[]
while i<n:
    y=raw_input().split(' ')
    l=int(y[0])
    r=int(y[1])
    brr.append(l)
    brr.append(r)
    if l==1:
        f.append(sm[r-1])
    else:
        f.append(sm[r-1]-sm[l-2])
    if i==0:
        fsm.append(f[i])
    else:
        fsm.append(fsm[i-1]+f[i])
    i=i+1
q=input()
i=0
while i<q:
    z=raw_input().split(' ')
    chk=int(z[0])
    a=int(z[1])
    b=int(z[2])
    if chk==2:
        if a==1:
            print fsm[b-1]
        else:
            print fsm[b-1]-fsm[a-2]
    else:
        arr[a-1]=b
        j=0
        while j<n:
            if j==0:
                sm[j]=arr[j]
            else:
                sm[j]=sm[j-1]+arr[j]
            j=j+1
        j=0
        while j<n:
            l1=brr[2*j]
            r1=brr[2*j+1]
            if l1==1:
                f[j]=sm[r1-1]
            else:
                f[j]=sm[r1-1]-sm[l1-2]
            if j==0:
                fsm[j]=f[j]
            else:
                fsm[j]=fsm[j-1]+f[j]
            j=j+1
    i=i+1

            
