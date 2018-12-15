t=input()
i=0
while i<t:
    maxir=0
    maxig=0
    maxib=0
    x=raw_input().split(' ')
    r=int(x[0])
    g=int(x[1])
    b=int(x[2])
    m=int(x[3])
    rx=raw_input().split(' ')
    j=0
    while j<r:
        if int(rx[j])>=maxir:
            maxir=int(rx[j])
        j=j+1
    rg=raw_input().split(' ')
    j=0
    while j<g:
        if int(rg[j])>=maxig:
            maxig=int(rg[j])
        j=j+1
    rb=raw_input().split(' ')
    j=0
    while j<b:
        if int(rb[j])>=maxib:
            maxib=int(rb[j])
        j=j+1
    j=0
    while j<m:
        if (maxir>=maxib and maxir>=maxig):
            maxir=maxir/2
            maxib+=1
            maxig+=1
        elif (maxib>=maxir and maxib>=maxig):
            maxib=maxib/2;
            maxir+=1
            maxig+=1
        else:
            maxig=maxig/2;
            maxir+=1
            maxib+=1
        j=j+1
    if (maxir>=maxib and maxir>=maxig):
        print maxir
    elif (maxib>=maxir and maxib>=maxig):
        print maxib
    else:
        print maxig
    i=i+1
