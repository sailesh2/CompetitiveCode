import math
t=input()
i=0
while i<t:
    n=input()
    a=math.pow(1+8*n,0.5)
    if a==int(a) and (int(a)-1)%2==0:
        print "Go On Bob "+str((int(a)-1)/2)
    else:
        print "Better Luck Next Time"
    i=i+1
