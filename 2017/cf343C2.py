x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])

s=raw_input()

if n%2!=0:
    print "0"
else:
    
    l=0
    r=0
    i=0
    while i<m:
        if s[i]=='(':
            l=l+1
        else:
            r=r+1
        i=i+1

    dif = n/2 - max(l,r)

    op=0
    ctrL=0
    i=0
    while i<m:
        if s[i]=='(':
            op=op+1
        else:
            if op>0:
                op=op-1
            else:
                ctrL=ctrL+1
        i=i+1

    cl=0
    ctrR=0
    i=m-1
    while i>=0:
        if s[i]==')':
            cl=cl+1
        else:
            if cl>0:
                cl=cl-1
            else:
                ctrR=ctrR+1
        i=i-1


    mod=1000000007
    i=1
    fac=[1]
    while i<=2*dif+m:
        fac.append((fac[i-1]*i)%mod)
        i=i+1

    sm=0
    i=0
    while i<=dif:
        lt=i
        rt=dif-i

        fl=1
        fr=1
        if lt>0:
            fl=(fac[2*lt]*(pow(fac[lt+1],mod-2,mod)*pow(fac[lt],mod-2,mod))%mod)%mod
        pl=(fl*(fac[lt*2+ctrL]*(pow(fac[lt*2],mod-2,mod)*(pow(fac[ctrL],mod-2,mod)))%mod)%mod)%mod
        if rt>0:
            fr=(fac[2*rt]*(pow(fac[rt+1],mod-2,mod)*pow(fac[rt],mod-2,mod))%mod)%mod
        pr=(fr*(fac[rt*2+ctrR]*(pow(fac[rt*2],mod-2,mod)*(pow(fac[ctrR],mod-2,mod)))%mod)%mod)%mod
        sm=(sm+(pl*pr))%mod

        i=i+1
    print sm
