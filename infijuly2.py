def E(a,b):
    if not a: return 0,1,b
    x,y,g=E(b%a,a)
    return y-(b/a)*x,x,g
t=input()
i=0
while i<t:
    z=raw_input().split(' ')
    a=int(z[0])
    b=int(z[1])
    x1=int(z[2])
    y1=int(z[3])
    
    c=x1
    x,y,g=E(a,b)
    C=-c/g
    if c%g:
        cnt=0
    else:
        cnt=1

    c=y1
    x,y,g=E(a,b)
    C=-c/g

    if c%g:
        cnt=0
    else:
        cnt=1
    if cnt==1:
        print "YES"
    else:
        print "NO"
    
    i=i+1
