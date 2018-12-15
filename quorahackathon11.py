n=input()
arr=[0]*(n+1)
x=raw_input().split(' ')
i=1
while i<=n:
    arr[i]=int(x[i-1])
    i=i+1
arr.sort()
m=input()
sm=0
i=0
while i<m:
    y=raw_input().split(' ')
    x1=int(y[0])
    y1=int(y[1])
    x2=int(y[2])
    y2=int(y[3])

    save=0
    save1=0
    while 1:
        save=save1
        ctr=1
        while 1:
            if save+ctr>n or ((x1**2+y1**2-(arr[save+ctr])**2)*(x2**2+y2**2-(arr[save+ctr])**2))<0:
                break
            if ((x1**2+y1**2-(arr[save+ctr])**2)*(x2**2+y2**2-(arr[save+ctr])**2))<=0:
                break
            save1=save+ctr
            ctr=ctr*2
        if save==save1:
            break
    ist=save
    if ist>n:
        ist=n
    while 1:
        save=save1
        ctr=1
        while 1:
            if save+ctr>n or ((x1**2+y1**2-(arr[save+ctr])**2)*(x2**2+y2**2-(arr[save+ctr])**2))>0:
                break
            save1=save+ctr
            ctr=ctr*2
        if save==save1:
            break
    if save>n:
        save=n
    if save>=ist:
        sm=sm+save-ist
    i=i+1
print sm









    
