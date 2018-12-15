import math
t=input()
i=0
while i<t:
    n=input()
    a=int(math.ceil((1+pow(1+8*n,0.5))/2))-1
    if a%3==0:
        print "SL"
    elif a%3==1:
        print "LB"
    else:
        print "BS"
    i=i+1
