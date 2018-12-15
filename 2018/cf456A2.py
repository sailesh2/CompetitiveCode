x=raw_input().split(' ')
y=int(x[0])
b=int(x[1])
x2=raw_input().split(' ')
yreq=int(x2[0])
greq=int(x2[1])
breq=int(x2[2])

y2=yreq*2+greq
b2=greq+3*breq

print max(0,y2-y)+max(0,b2-b)
