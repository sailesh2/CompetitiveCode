x=raw_input().split(' ')
n=int(x[0])
q=int(x[1])
s=raw_input()
brr=[]
arr=[0]*n
zero=[0]*n
one=[0]*n
two=[0]*n
sumz=0
sumo=0
sumt=0
i=0
while i<n:
    brr.append(int(s[i]))
    if i!=0:
        brr[i]=(brr[i]+brr[i-1])%3
    brr[i]=brr[i]%3
    i=i+1
i=1
while i<=n:
    val=1;
    if (brr[i-1]==0):
        idx=i;
        while (idx <=n):
            zero[idx-1] += val;
            idx += (idx & -idx);
    elif (brr[i-1]==1):
        idx=i;
        while (idx <=n):
            one[idx-1] += val;
            idx += (idx & -idx);
    else:
        idx=i;
        while (idx <=n):
            two[idx-1] += val;
            idx += (idx & -idx);
    if (i!=1):
        val=(brr[i-1]-brr[i-2])%3;
        if val<0:
            val=val+3	
    else:
        val=brr[i-1];
    idx=i;
    while (idx<=n):
        arr[idx-1] += val;
        idx += (idx & -idx);
    i=i+1
i=0
while i<q:
    y=raw_input().split(' ')
    p=int(y[0])
    a=int(y[1])
    b=int(y[2])
    if p==2:
        idx=a-1;
        sm = 0;
        while (idx > 0):
            sm += arr[idx-1];
            idx -= (idx & -idx);
        cntz=sm%3;
        cnto=(sm+1)%3;
        cntt=(sm+2)%3;
        
        if (cntz==0):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
 
            sumz=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
            sumz=sumz-sm
        elif (cntz==1):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
 
            sumz=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
            sumz=sumz-sm
        else:
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
 
            sumz=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
            sumz=sumz-sm
        
        if (cnto==0):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
 
            sumo=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
            sumo=sumo-sm
        elif (cnto==1):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
 
            sumo=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
            sumo=sumo-sm
        else:
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
 
            sumo=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
            sumo=sumo-sm
        
        if (cntt==0):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
 
            sumt=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += zero[idx-1];
                idx -= (idx & -idx);
            sumt=sumt-sm
        elif (cntt==1):
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
 
            sumt=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += one[idx-1];
                idx -= (idx & -idx);
            sumt=sumt-sm
        else:
            idx=b;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
 
            sumt=sm
            idx=a-1;
            sm = 0;
            while (idx > 0):
                sm += two[idx-1];
                idx -= (idx & -idx);
            sumt=sumt-sm
        print (sumz*(sumz+1))/2+(sumo*(sumo-1))/2+(sumt*(sumt-1))/2
    else:
        idx=a;
        sm = 0;
        while (idx > 0):
            sm += arr[idx-1];
            idx -= (idx & -idx);
        dif=sm
        idx=a-1
        sm=0
        while (idx > 0):
            sm += arr[idx-1];
            idx -= (idx & -idx);
        dif=dif-sm
        dif=b-dif
        
        j=a
        while j<=n:
            idx=j
            sm = 0;
            while (idx > 0):
                sm += arr[idx-1];
                idx -= (idx & -idx);
            sm=sm%3
            if sm==0:
                val=-1
                idx=j
                while (idx <=n):
                    zero[idx-1] += val
                    idx += (idx & -idx);
            elif sm==1:
                val=-1
                idx=j
                while (idx <=n):
                    one[idx-1] += val
                    idx += (idx & -idx);
            else:
                val=-1
                idx=j
                while (idx <=n):
                    two[idx-1] += val
                    idx += (idx & -idx);
            sm=(sm+dif)%3
            if sm<0:
                sm=sm+3
            if sm==0:
                val=1
                idx=j
                while (idx <=n):
                    zero[idx-1] += val
                    idx += (idx & -idx);
            elif sm==1:
                val=1
                idx=j
                while (idx <=n):
                    one[idx-1] += val
                    idx += (idx & -idx);
            else:
                val=1
                idx=j
                while (idx <=n):
                    two[idx-1] += val
                    idx += (idx & -idx);
            j=j+1
        idx=a
        while (idx <=n):
            arr[idx-1] = (arr[idx-1] + dif)%3
            idx += (idx & -idx);  
    i=i+1
