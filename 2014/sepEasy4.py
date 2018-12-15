import math
t=input()
i=0
while i<t:
    n=input()
    s=0
    j=1
    a=int(math.ceil(n**(0.5)))
    while j<=a:
    	s=s+int(math.floor(float(n)/j))-1
    	j=j+1
    print s
    i=i+1
