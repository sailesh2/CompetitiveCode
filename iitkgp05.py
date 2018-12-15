t=input()
i=0
while i<t:
    x=raw_input()
    cnt=0
    j=1
    while j<len(x):
        if x[j]==x[j-1]:
            cnt=1
            break
        j=j+1
    if cnt==0:
        print "KISS"
    else:
        print "SLAP"
    i=i+1
