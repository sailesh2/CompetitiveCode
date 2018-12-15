t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    c=pow(a,b)
    print c
    sm=0
    while c!=0:
        sm=sm+c%10
        c=c/10
    print "Case "+str(i+1)+": "+str(sm)
    i=i+1
