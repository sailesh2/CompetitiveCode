import math
q=int(raw_input())
p=[0,1,1,1]
i=4
while i<=3001:
    j=2
    cnt=1
    while j<i:
        if i%j==0:
            cnt=0
            break
        j=j+1
    p.append(cnt)
    i=i+1
i=0
while i<q:
    n=int(raw_input())
    j=4
    save=-1
    while j<=int(math.ceil(n**0.5)):
        if p[j]==0 and n%j==0:
            save=n/j
            break
        j=j+1
    print save
    i=i+1
