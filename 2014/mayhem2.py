t=input()
i=0
while i<t:
    n=input()
    j=0
    save=-1
    save2=-1
    maxim=0
    maxim2=0
    s=0
    saven=-1
    saven2=-1
    while j<n:
        x=raw_input().split(' ')
        f=int(x[0])
        a=int(x[1])
        s=s+a
        if f+a>=maxim:
            if maxim>=maxim2:
                maxim2=maxim
                save2=save
                saven2=saven
            maxim=f+a
            save=a
            saven=f
        elif f+a>=maxim2:
            maxim2=f+a
            save2=a
            saven2=f
        j=j+1
    print save,save2
    s=s-save-save2
    print saven+saven2-s
    i=i+1
