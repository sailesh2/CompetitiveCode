t=input()
i=0
while i<t:
    num=input()
    s=0
    j=1
    while j*j<=num:
        if num%j==0:
            if j%4!=0:
                s=s+j
            if (num/j)%4!=0:
                s=s+num/j
        if j*j==num:
            if j%4!=0:
                s=s-j
        j=j+1
    print 8*s
    i=i+1
