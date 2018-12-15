t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    r=int(x[0])
    k=int(x[1])
    v=int(x[2])
    max1=max(r,max(k,v))
    if r==max1:
        max2=max(k,v)
    elif k==max1:
        max2=max(r,v)
    else:
        max2=max(r,k)
    if max1==max2:
        print 2*max1
    else:
        print 2*max2+1
    i=i+1
