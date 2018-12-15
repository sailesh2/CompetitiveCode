t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    ans=float(a-b)/(a+b)
    print "%.12f" % ans
    i=i+1
