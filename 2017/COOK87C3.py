def binSear(y):
    ctr=1;
    save=0;
    save2=0;

    while(1):
        while (ctr+save)*(ctr+save)<=y:
            save2=save+ctr;
            ctr=ctr*2;
        
        if (save==save2):
            break;

        save=save2;
        ctr=1;
    return save

t=int(raw_input())
i=0
while i<t:
    y=int(raw_input())
    b=1
    ctr=0
    while b<=700:
        if y-b<=0:
            break
        
        ctr=ctr+binSear(y-b)
        b=b+1
    print ctr
    i=i+1
