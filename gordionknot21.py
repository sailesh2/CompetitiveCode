ctr=0
i=1
while i<=2**8:
    arr=[i,2*i,3*i]
    sm=0
    j=0
    while j<3:
        sm=sm^arr[j]
        j=j+1
    cnt=0
    j=0
    while j<3:
        if sm^arr[j]<arr[j]:
            cnt=1
            break
        j=j+1
    if cnt==0:
        ctr=ctr+1
    i=i+1
print ctr
