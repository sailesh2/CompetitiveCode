import math
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    h=int(x[1])
    th=int(x[2])
    #print phi
    pie=3.141593
    if th==0 or h==0:
        print h
    else:
        phi=((180*math.atan(float(h)/a))/pie)
  
        if float(th)<phi:
            print int((h-(a/2)*math.tan(float(pie*th)/180)))+1
        else:
            print min(a,int((float(h**2)/(2*a*math.tan((pie*th)/180))))+1)
    i=i+1
