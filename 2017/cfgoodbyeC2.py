x=raw_input().split(' ')
n=int(x[0])
r=int(x[1])

xp=raw_input().split(' ')
xpos=[]
i=0
while i<n:
    xpos.append(int(xp[i]))
    i=i+1

ypos=[]
i=0
while i<n:
    j=0
    maxy=r
    while j<i:
        v=4*r*r-(xpos[j]-xpos[i])**2
        if v>=0:
            a=v**0.5+ypos[j]
            b=ypos[j]-v**0.5
            if a>=0 and b>=0:
                maxy=max(maxy,max(a,b))
            elif a>=0:
                maxy=max(maxy,a)
            elif b>=0:
                maxy=max(maxy,b)

        j=j+1
    ypos.append(maxy)
    i=i+1
i=0
while i<n:
    print ypos[i],
    i=i+1
