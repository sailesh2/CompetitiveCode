import math
t=int(raw_input())
i=0
while i<t:
    y=int(raw_input())
    ctr=0
    
    lt=int(math.floor(pow(y-1,0.5)))
    st=int(math.floor(pow(max(y-700,0),0.5)))
    
    while st<=lt:
        p1=pow(st,2)
        p2=pow(st+1,2)
        ctr=ctr+st*((min(y,p2)-max(y-700,p1)))
        st=st+1
    
    print ctr
    i=i+1
