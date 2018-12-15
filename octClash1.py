t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    y=raw_input().split(' ')
    z=raw_input().split(' ')
    maxi=0
    j=0
    while j<n-1:
        a=int(z[j])
        if int(y[a-1])>=maxi:
            maxi=int(y[a-1])
        print x[a-1],maxi
        j=j+1
        x.remove(x[a-1])
        y.remove(y[a-1])
    if maxi>=int(y[0]):
        maxi=int(y[0])
    print x[0],maxi
    i=i+1
