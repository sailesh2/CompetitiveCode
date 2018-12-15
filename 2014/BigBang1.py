t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    z=int(x[0])
    n=int(x[1])
    y=raw_input().split(' ')
    j=0
    while j<n:
        z=z & int(y[j])
        j=j+1
    if z==0:
        print "Yes"
    else:
        print "No"
    i=i+1
