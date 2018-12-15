t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    j=len(x)-1
    while j>=0:
        print x[j],
        j=j-1
    print
    i=i+1
