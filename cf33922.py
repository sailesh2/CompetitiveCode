import math
n=input()
x=raw_input().split(' ')
p=1
i=0
sm=0
while i<n:
    if int(x[i])==0:
        p=0
        break
    ctr=1
    cnt=0
    num=int(x[i])
    while num>0:
        ctr=ctr*10
        val=num%10
        if val>1:
            cnt=2
            break
        if val==1:
            if cnt==1:
                cnt=2
                break
            cnt=1
        num=num/10
    if cnt==2:
        p=p*int(x[i])
    else:
        p=p*ctr/10
    i=i+1

print p
