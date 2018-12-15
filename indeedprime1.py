x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
c=int(x[2])

y1=a+b+c
y2=a+b*c
y3=a*b+c
y4=a*b*c
if y1==42 or y2==42 or y3==42 or y4==42:
    if y1==42:
        print str(a)+'+'+str(b)+'+'+str(c)
    elif y2==42:
        print str(a)+'+'+str(b)+'*'+str(c)
    elif y3==42:
        print str(a)+'*'+str(b)+'+'+str(c)
    elif y4==42:
        print str(a)+'*'+str(b)+'*'+str(c)
else:
    print 'This is not the ultimate question'
