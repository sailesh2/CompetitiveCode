n=input()
arr=[0,0,0,0,0,0]
ctr=0
i=0
while i<n:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    if arr[a]==0 and arr[b]==0:
        arr[b]=arr[a]=a
        ctr=ctr+1
    elif arr[a]==0:
        k=arr[b]
        while 1:
            if k==arr[b]:
                break
            k=arr[b]
        arr[a]=k
    else:
        k=arr[a]
        while 1:
            if k==arr[a]:
                break
            k=arr[a]
        arr[b]=k
    i=i+1
if ctr==0:
    print "WIN"
else:
    i=1
    ctr2=0
    while i<=5:
        j=1
        ctr2=0
        while j<=5:
            if arr[j]==i:
                ctr2=ctr2+1
            j=j+1
        if ctr2==3:
            print "WIN"
            break
        i=i+1
    if ctr2!=3:
        print "FAIL"
        
        
    
