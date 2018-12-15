import math
x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
n=int(x[2])
i=0
while i<n:
    y=raw_input().split(' ')
    l=int(y[0])
    t=int(y[1])
    m=int(y[2])


    r=int(math.floor(float((t-a))/b))+1
    if l>r:
        print "-1"
    else:
        
        if r-l+1<=m or a<=(2*m-r)*b:
            print r
        else:
        
            ctr=1
            save2=r
            while 1:
                save=save2
                while r>=l:
                    r=r-ctr
                    if a<=(2*m-r)*b or r-l+1<=m:
                        r=save2
                        ctr=1
                        break
                    save2=r
                    ctr=ctr*2
                if save==save2:
                    break
            print save-1
    i=i+1
