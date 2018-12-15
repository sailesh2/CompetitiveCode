

six=[1,6,15,20,15,6,1];
ans=[0]*7
n=input()
n=n-13
if n<0: 
    print "0";
elif n==0:
    print "1";
else:
    s=1
    ans[0]=s
    s=s+six[1]*1
    ans[1]=s

    s=s+six[1]*1+six[2]*1
    ans[2]=s

    s=s+six[1]*1+six[2]*2+six[3]*1
    ans[3]=s

    s=s+six[1]*1+six[2]*3+six[3]*3+six[4]*1
    ans[4]=s

    s=s+six[1]*1+six[2]*4+six[3]*6+six[4]*4+six[5]*1
    ans[5]=s

    s=s+six[1]*1+six[2]*5+six[3]*10+six[4]*10+six[5]*5+six[6]*1
    ans[6]=s

    if n%2!=0:
        n=n-1
    n=n/2
    if n<=6:
        print ans[n]
    else:
        i=1
        j=n
        p=1
        while i<=6:
            p=p*i
            k=j/p
            s=(s+(k-six[i])*six[i])
            j=j*(n-i)
            i=i+1
        print s%1000000007;
   
