t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    a=3
    j=n
    while j<=m:
        if j==2:
            print 2
        if j%2!=0:
            if j%a==0:
                if pow(a+1,j-1,j)==1:
                   print j
            else:
                if pow(a,j-1,j)==1:
                   print j
        j=j+1
    print 
    i=i+1
