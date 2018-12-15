x=input().split(' ')
n=int(x[0])
L=int(x[1])
a=int(x[2])

i=0
sm=0
bef=0
while i<n:
    y=input().split(' ')
    t=int(y[0])
    tl=int(y[1])
    sm=sm+int((t-bef)/a)
    bef=t+tl;
    i=i+1
sm=sm+int((L-bef)/a)
print(sm)
