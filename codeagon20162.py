
has=[0]
i=1
while i<=1000000:
    cnt=0;
    ctr=0;
    n=i;
    while (n%2 == 0):
        if(n<i):
            ctr=ctr+has[n];
            cnt=1;
            break;
        ctr=ctr+1;
        n = n/2;
    if(cnt==0):
        j=3;
        while(j*j<=n):
            while (n%j == 0):
                if(n<i):
                    cnt=1;
                    ctr=ctr+has[n];
                    break;
                ctr=ctr+1;
                n = n/j;
            if(cnt==1):
                break;
            j=j+2

    if (cnt==0 and n > 2):
        ctr=ctr+1;
    has.append(ctr);
    i=i+1

i=1
while i<=1000000:
    has[i]=has[i]+has[i-1];
    i=i+1
    
    n=input()
    arr=[]
    sumi=0;
    i=0
    while i<n:
        arr[i]=input()
        arr[i]=has[arr[i]];
        i=i+1

    i=0
    while i<n:
        sm=0;
        j=i
        while j<n:
            sm=sm+arr[j];
            if(sm%2==0):
                sumi=sumi+sm;
            j=j+1
        i=i+1
    print sumi;
