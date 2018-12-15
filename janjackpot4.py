t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    if b<7:
        print "0"
    elif b>=7 and b<13:
        if a<=7:
            print "8"
        else:
            print "0"
    else:
        if a<=7:
            print "152"
        elif a>7 and a<=13:
            print "144"
        else:
            print "0"
    i=i+1
