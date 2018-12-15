import math
n=input()
nsave=n
d=int(math.floor(math.log10(n)))
if d<2:
    print n
else:
    k=int(math.pow(2,d))
    c=int(math.pow(10,d))
    save=c*10
    s=(n/c-1)*((k-2)*9+10)+99
    fir=n/c
    n=n%c
    c=c/10
    sec=n/c
    j=0
    while j<sec:
        if j==fir:
            s=s+(k/2-2)*9+10
        else:
            s=s+k/2-1
        j=j+1
    s=s+sec
    n=n%c
    print k,s
    #print n
    if fir==sec:
        j=0
        #print "e"
        while j<10 :
            if j!=sec:
         #       print j
                if j<=sec:
                    mini=j
                else:
                    mini=sec        
                p=mini*(c-1)/9
                #print p
                i=0
                while i<k:
                    m=i
                    sm=0
                    t=1
                    while m>0:
                        a=m%2
                        sm=sm+t*a
                        m=m/2
                        t=t*10
     #               print sm
                    if p+sm*abs(j-sec)>n:
                        break
                    else:
                        if mini==fir:
                            if (((p+sm*abs(j-sec))/mini)*9+1)%10!=0:
                                s=s+1
                        else:
                            s=s+1
                    i=i+1
            j=j+1
    else:
        if fir<=sec:
            mini=fir
        else:
            mini=sec        
        p=mini*(c-1)/9
        print n,p
        i=0
        while i<k:
            m=i
            sm=0
            t=1
            while m>0:
                a=m%2
                sm=sm+t*a
                m=m/2
                t=t*10
            print sm
            if p+sm*abs(fir-sec)>n:
                break
            else:
                s=s+1
            print s
            i=i+1
    if nsave%(save/10)==0:
        s=s-1
    if (save-1)/9<=nsave:
        print s+1
    else:
        print s
