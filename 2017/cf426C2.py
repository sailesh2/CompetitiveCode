import math
n=int(raw_input())
i=0
while i<n:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    l=a*b
    y=math.ceil(math.pow(l,(1.0/3.0)))
    if abs(y*y*y-l)==0 and a%y==0 and b%y==0:
        print "Yes"
    else:
      print "No"
    i=i+1
