import math
x=int(raw_input())
a=math.log(x,2)
if(int(a)==a):
    print int(a)
else:
    print int(math.floor(a))+1
