t=input()
i=0
while i<t:
    n=input()
    k=input()
    s=0
    s1=0
    j=1
    while j<=n:
        s=s+(j**k)
        s1=s1+((j%100)**k)
        j=j+1
    print s%100,s1%100
    i=i+1
