x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
z=int(x[2])
y=raw_input().split(' ')
arr=[]
count=[0]*1000
i=0
while i<n:
    arr.append(int(y[i]))
    val=arr[i]
    ctr=0
    while val>0:
        a=val%2
        if a==1:
            count[ctr]=count[ctr]+1
        val=val/2
        ctr=ctr+1
    i=i+1
i=0
while i<k:
    j=0
    maxi=-1
    save=-1
    while j<n:
        final=arr[j]*z
        val=final
        val2=arr[j]
        ctr=0
        save_local=-1
        save_local2=-1
        while val>0 or val2>0:
            a=val%2
            b=val2%2
            if a==1:
                if count[ctr]==0:
                    save_local=ctr
            else:
                if count[ctr]==1 and b==1:
                    save_local2=ctr
            val=val/2
            val2=val2/2
            ctr=ctr+1
        if save_local>save_local2:
            if save_local>maxi:
                maxi=save_local
                save=j
        j=j+1
    if save==-1:
        break
    val=arr[save]
    ctr=0
    while val>0:
        a=val%2
        if a==1:
            count[ctr]=count[ctr]-1
        val=val/2
        ctr=ctr+1
    ctr=0
    arr[save]=arr[save]*z
    val=arr[save]
    while val>0:
        a=val%2
        if a==1:
            count[ctr]=count[ctr]+1
        val=val/2
        ctr=ctr+1
    i=i+1
i=0
s=0
while i<n:
   s=s | arr[i]
   i=i+1
print s



        
