x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
c=int(x[2])

ctr=1
save=-1
while ctr<500000:
    r=a%b
    if r==0:
        if c==0:
            save=ctr
        break
    d=(r*10)/b
    if d==c:
        save=ctr
        break
    a=r*10
    ctr=ctr+1
print save
