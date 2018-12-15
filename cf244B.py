
st=1000
ctr2=0
while st<2000:
    ctr=0
    n=st
    arr=[0]*10
    while n!=0:
        a=n%10
        if arr[a]==0:
            ctr=ctr+1
            arr[a]=1
        if ctr>2:
            break
        n=n/10
    if ctr<=2:
        print st
        ctr2=ctr2+1
    st=st+1
print ctr2
