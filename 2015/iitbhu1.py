import math
n=input()
if n>0:
    x=raw_input().split(' ')
i=0
sm=0
while i<n:
    sm=sm+int(x[i])
    i=i+1
if sm==0:
    print sm+2
else:
    ans=2**int(math.ceil(math.log(sm,2)))
    if ans==1:
        print ans+1
    else:
        print ans
