import math
x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
y=raw_input().split(' ')
maxi=0
save=-1
i=0
while i<n:
    a=int(math.ceil(float(int(y[i]))/m))
    if a>=maxi:
        maxi=a
        save=i
    i=i+1
print save+1
