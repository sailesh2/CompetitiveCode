x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
i=1
sm=0
while 1:
    if n-i==0 or m-i==0:
        break
    sm=sm+(n-i)*(m-i)
    i=i+1
print n*m + 2*(sm)
