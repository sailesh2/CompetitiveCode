import math
x=input().split(' ')
n=int(x[0])
r=int(x[1])


tan2 = (math.tan(math.radians(180/n)))**2

R = r*tan2*(1+(1+1/tan2)**0.5)

print("%.7f"%R)
