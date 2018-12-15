n=input()
dist=[]
save=[0]*1000000
sm=1
dist.append(1)
dist.append(2)
save[1]=1
save[2]=2
i=1
while 1:
    p=save[dist[i]]
    q=dist[i-1]
    if i!=1:
        dist.append(p*q)
    if p*q>n:
        break
    sm=sm+(p*q)    
    j=1
    ctr=0
    while j<=(p*q):
        if (p*q)%j==0:
            ctr=ctr+1
        j=j+1
    save[p*q]=ctr
    p=dist[i]
    q=save[dist[i]]
    dist.append(p*q)
    if p*q>n:
        break
    sm=sm+(p*q)
    j=1
    ctr=0
    while j<=(p*q):
        if (p*q)%j==0:
            ctr=ctr+1
        j=j+1
    save[p*q]=ctr
    i=i+1
print sm
