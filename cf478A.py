x=raw_input().split()
sm=0
i=0
while i<5:
    sm=sm+int(x[i])
    i=i+1
if sm%5==0 and sm!=0:
    print sm/5
else:
    print "-1"
