t=input()

i=0
while i<t:
    x=raw_input().split(' ')
    h=int(x[0])
    n=int(x[1])
    m=int(x[2])

    k=(h-n)/(n-m)
    if k*(n-m)+n<h:
        k=k+1
    dis=k*(n-m)
    print "%.2f"%(k+float(h-dis)/n)
    i=i+1
