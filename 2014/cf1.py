x=raw_input().split(' ')
x1=int(x[0])
y1=int(x[1])
x2=int(x[2])
y2=int(x[3])
if x1==x2 or y1==y2 or float(y2-y1)/(x2-x1)==1:
    if x1==x2:
        d=abs(y2-y1)
        print x1+d,y1,x2+d,y2
    elif y1==y2:
        d=abs(x2-x1)
        print x1,y1+d,x2,y2+d
    else:
        print x1,y2,x2,y1
else:
    print "-1"
