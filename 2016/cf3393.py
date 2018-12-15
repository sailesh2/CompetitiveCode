x=raw_input().split(' ')
n=int(x[0])
a=int(x[1])
b=int(x[2])
maxi=0
mini=1000000000000
i=0
ctr=0
while i<n:
    y=raw_input().split(' ')
    l=int(y[0])
    r=int(y[1])
    
    d=(l-a)*(l-a)+(r-b)*(r-b)
    if d==mini:
        ctr+=1
        if ctr==1:
            savel2=l
            saver2=r
    if d<mini:
        mini=d
        savel=l
        saver=r
        ctr=0
    if d>maxi:
        maxi=d
    i=i+1
if ctr<1:
    print 3.1415926535897931*(maxi-mini)
else:
    midx=float(savel+savel2)/2
    midy=float(saver+saver2)/2
    mini=(a-midx)*(a-midx)+(b-midy)*(b-midy)
    print 3.1415926535897931*(maxi-mini)
