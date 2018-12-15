n=1000
a=[0,1]

i=2
while i<=n**0.5:
    if i not in a:
        j=i*i
        while j<=n:
            a.append(j)
            j=j+i
    i=i+1
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n1=int(x[0])
    m=int(x[1])
    arr=[0,1]
    j=2
    while j<=m**0.5:
        if j not in a:
            k=n1/j
            k=k*j
            while k<=m:
                if k!=j:
                    arr.append(k)
                k=k+j
        j=j+1
    j=n1
    while j<=m:
        if j not in arr:
            print j
        j=j+1
    print 
    i=i+1
