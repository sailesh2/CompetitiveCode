import math

x=int(input())
if x==1:
    print("1")
elif x==2:
    print("1 2")
elif x==3:
    print("1 1 3")
else:
    ev=int(2**int(math.log(x,2)))
    if x%2==0:
        last=x
    else:
        last=x-1
        
    rest=0
    ans=[]
    while rest<x:
        c=int(x/ev)
        i=0
        while i<c-rest:
            ans.append(ev)
            i=i+1
        ev=int(ev/2)
        if ev==0:
            break
        rest=len(ans)

    i=len(ans)-1
    v=int(last/ans[1])+1
    
    if ans[1]*v<=last:
        ans[0]=ans[1]*v
    elif ans[1]*(v-1)<=last:
        ans[0]=ans[1]*(v-1)
    while i>=0:
        print(ans[i],end=' ')
        i=i-1
    
