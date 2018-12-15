n=input()
arr=[0]*4
arr[n]=1
i=0
while i<3:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    if arr[a]==1:
        arr[1]=0
        arr[2]=0
        arr[3]=0
        arr[b]=1
    elif arr[b]==1:
        arr[1]=0
        arr[2]=0
        arr[3]=0
        arr[a]=1
    i=i+1
i=1
while i<=3:
    if arr[i]==1:
        print i
        break
    i=i+1
