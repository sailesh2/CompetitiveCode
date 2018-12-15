t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    j=0
    ctr=0
    cnt2=0
    cnt3=0
    while j<n:
        if cnt2==0 and int(x[j])==2:
            cnt2=1
            ctr=ctr+1
        if cnt3==0 and int(x[j])==3:
            cnt3=1
            ctr=ctr+1
        j=j+1
    print ctr
    i=i+1
