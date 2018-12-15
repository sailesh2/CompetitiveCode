t=input()

i=0
while i<t:
    n=input()
    j=0
    save=0
    ctr=1
    while 1:
        while ((j+ctr)*(j+ctr+1)*(2*(j+ctr)+1))/6<=n:
            save=j+ctr
            ctr=ctr*2
        if save==j:
            break
        ctr=1
        j=save
    print save
    i=i+1
            
