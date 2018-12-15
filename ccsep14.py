t=input()
i=0
while i<t:
    s=raw_input()
    lt=len(s)
    p=1
    k=0
    cnt=0
    j=0
    while j<lt:
        p=p*2
        if s[j]=='l':
            k=(k*2)
        else:
            k=(k*2+1)
        cnt=1-cnt
        j=j+1
    if cnt==0:
        print ((6*k+2*p+1)/3)%1000000007
    else:
        print ((6*k+2*p+2)/3)%1000000007
    i=i+1
        
