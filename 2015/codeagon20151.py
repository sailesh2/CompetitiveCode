x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
if m>((n*(n+1))/2):
    print "-1"
else:
    sm=0
    ctr=n
    cnt=0
    while ctr>0:
        if m<=sm:
            break
        sm=sm+ctr
        cnt=cnt+1
        ctr=ctr-1
    print cnt
