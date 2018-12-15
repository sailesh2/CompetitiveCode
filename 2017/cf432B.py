import math
from math import radians
x=raw_input().split(' ')
x1=int(x[0])
y1=int(x[1])
x2=int(x[2])
y2=int(x[3])
x3=int(x[4])
y3=int(x[5])

i=0
cnt=0
while i<=360:
    a1=x2-(x1*math.cos(radians(i)) + y1*math.sin(radians(i)))
    b1=y2-(y1*math.cos(radians(i)) - x1*math.sin(radians(i)))

    a2=x3-(x2*math.cos(radians(i)) + y2*math.sin(radians(i)))
    b2=y3-(y2*math.cos(radians(i)) - x2*math.sin(radians(i)))

    if a1==a2 and b1==b2:
        cnt=1
        break
    i=i+1

if cnt==0:
    print "No"
else:
    print "Yes"
