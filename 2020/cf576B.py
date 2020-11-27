y=input().split(' ')
h=int(y[0])
l=int(y[1])

x=float(l*l - h*h)/(2*h)
print("%.13f" % x)
