x=raw_input().split(' ')
n=int(x[0])
inh=int(x[1])


typ=[]
ht=[]
mass=[]
maxi=0
i=0
cnt=0
while i<n:
    y=raw_input().split(' ')
    typ.append(int(y[0]))
    ht.append(int(y[1]))
    mass.append(int(y[2]))
    if ht[i]<=inh and mass[i]>=maxi:
        cnt=1
        ctr0=typ[i]
        maxi=mass[i]
    i=i+1
if cnt==0:
    print "0"
else:
    already=[0]*n
    sm=0
    while 1:
        i=0
        maxi=0
        cnt=0
        while i<n:
            if already[i]==0 and typ[i]==ctr0 and ht[i]<=inh:
                cnt=1
                if mass[i]>=maxi:
                    save=i
                    maxi=mass[i]
            i=i+1
        if cnt==0:
            break
        already[save]=1
        inh=inh+maxi
        sm=sm+1
        ctr0=1-ctr0
    print sm
