inp=raw_input().split(' ')
R=int(inp[0])
x1=int(inp[1])
y1=int(inp[2])
x2=int(inp[3])
y2=int(inp[4])

d=((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1))**0.5
x31=x1+(float(R)/d)*(x2-x1)
y31=y1+(float(R)/d)*(y2-y1)

x32=x1-(float(R)/d)*(x2-x1)
y32=y1-(float(R)/d)*(y2-y1)

d1=((x31-x2)*(x31-x2) + (y31-y2)*(y31-y2))**0.5
d2=((x32-x2)*(x32-x2) + (y32-y2)*(y32-y2))**0.5

x3=0
y3=0
r=0
if d1>d2:
    x3=x31
    y3=y31
    r=float(d1)/2
else:
    x3=x32
    y3=y32
    r=float(d2)/2

x3c=float(x2+x3)/2
y3c=float(y2+y3)/2

print x3c,y3c,r
