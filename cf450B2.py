def fractionToDecimal( numr,  denr):

    mp={}
    rem = numr%denr;
    res=""
    while ( (rem!=0) and (rem not in mp )):
        
        mp[rem] = len(res)
 
        rem = rem*10;
        res_part = str(rem / denr);
        res = res+ (res_part);
 
        rem = rem % denr;
 
    if rem==0:
        return ""
    else:
        v=mp[rem]
        return res[v:]


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
    rep=fractionToDecimal(a,b)
    if len(rep)>0 and rep in after:
        pos=after.find(rep)
        i=0
        save2=-1
        while i<pos+len(rep) and i<len(after):
            if after[i]==str(c):
                save2=i+1
                break
            i=i+1
        print save2
    else:
        v= (after.find(str(c)))+1
        if v==0:
            if c==0:
                print len(after)+1
            else:
                print "-1"
        else:
            print v
    
    
        
    
