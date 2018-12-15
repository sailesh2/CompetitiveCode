t=input()
i=0
while i<t:
    x=raw_input()
    j=len(x)-1
    sm=int(x[j])
    j=j-1
    while j>=0:
        c=x[j]
        j=j-1
        a=int(x[j])
        if c=='*':
            sm=sm*a
        elif c=='+':
            sm=sm+a
        else:
            sm=sm-a
        j=j-1
    print sm
    i=i+1
