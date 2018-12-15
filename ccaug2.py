t=input()
i=0
while i<t:
    n=raw_input().split(' ')
    x=int(n[0])
    y=int(n[1])
    cnt1=0
    cnt2=0
    if x!=0 and ((abs(x)%2==0 and x<0) or (abs(x)%2!=0 and x>0)):
        r=abs(x)
        yr=r-1
        yr2=r
        if yr==0:
            lp=0
        elif yr%2==0:
            lp=-1*yr
        else:
            lp=yr+1
        if yr2%2==0:
            rp=-1*yr2
        else:
            rp=yr2+1
        if lp<=rp:
            if y>=lp and y<=rp:
                cnt1=1
            else:
                cnt1=0
        else:
            if y>=rp and y<=lp:
                cnt1=1
            else:
                cnt1=0
    if abs(y)%2==0:
        if y==0:
            if x==0 or x==1:
                cnt2=1
            else:
                cnt2=0
        else:
            if y>0:
                r=abs(y)-1
            else:
                r=abs(y)
            xr=r+1
            if xr%2==0:
                lp=-1*xr
                rp=lp+(2*xr-1)
            else:
                rp=xr
                lp=rp-(2*xr-1)
            if lp<=rp:
                if x>=lp and x<=rp:
                    cnt2=1
                else:
                    cnt2=0
            else:
                if x>=rp and x<=lp:
                        cnt2=1
                else:
                    cnt2=0
    if cnt1==1 or cnt2==1:
        print "YES"
    else:
        print "NO"
    i=i+1
