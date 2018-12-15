t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    sm=0
    j=1
    while j<=n:
        k=j-1
        while k>=1:
            if int(x[k])>int(x[j]):
                sm+=1
            k=k-1
        j=j+1
    print sm
    i=i+1
