t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    sm=0
    j=0
    while j<n:
        sm=sm^int(x[j])
        j=j+1
    j=0
    cnt=0
    while j<n:
        if sm^int(x[j])<int(x[j]):
            cnt=1
            break
        j=j+1
    if cnt==0:
        print "-1"
    else:
        print sm
    i=i+1
