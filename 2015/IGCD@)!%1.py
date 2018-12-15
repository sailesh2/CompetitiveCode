t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    init=int(x[1])
    final=int(x[3])
    lif=int(x[2])

    y=raw_input().split(' ')
    man=int(y[1])
    lift=int(y[0])

    dif_lif=abs(lif-init)+abs(init-final)

    dif_man=abs(init-final)


#    print dif_lif,dif_man
#    print dif_lif*lift
#    print dif_man*man
    if dif_lif*lift<=dif_man*man:
        print "LIFT"
    else:
        print "STAIRS"
    i=i+1
