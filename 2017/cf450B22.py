

x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
c=int(x[2])

dec=str(float(a)/b)
i=0
save=-1
while i<len(dec):
    if dec[i]=='.':
        cnt=1
        save=i
        break
    i=i+1
if save==-1:
    if c==0:
        print "1"
    else:
        print "-1"
else:
    after=dec[save+1:]
    rep=1
    ctrb=0
    while 1:
        if b%2==0:
            b=b/2
        else:
            break
    
    while 1:
        if b%5==0:
            b=b/5
        else:
            break
    if b==1:
        rep=0
    v= (after.find(str(c)))+1
    if v==0:
        if rep==0:
            if c==0:
                print len(after)+1
            else:
                print "-1"
        else:
            print "-1"
    else:
        print v
    
    
        
    
