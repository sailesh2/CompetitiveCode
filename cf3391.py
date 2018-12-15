import math
x=raw_input().split(' ')
l=int(x[0])
r=int(x[1])
k=int(x[2])
p=1
cnt=0
while 1:
    if p>r:
        break
    if p>=l and p<=r:
        cnt=1
        print p,
    p=p*k
    
if cnt==0:
    print "-1"
