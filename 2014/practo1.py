import math
t=input()
i=0
s=0
while i<t:
    n=input()
    s=s+n
    i=i+1
print int(math.ceil(float(s)/n))
