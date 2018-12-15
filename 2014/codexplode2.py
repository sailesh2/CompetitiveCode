t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    p=int(x[1])
    arr=[]
    y=raw_input().split(' ')
    cnt=0
    sm=0
    j=0
    while j<n:
        sm=sm+int(y[j])
        if sm>=p:
            if sm-p in arr or sm==p:
                cnt=1
                print "Yes"
                break
        arr.append(sm)
        j=j+1
    if cnt==0:
        print "No"
    i=i+1
