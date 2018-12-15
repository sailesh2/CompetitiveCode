x=raw_input().split(' ')
r=int(x[0])
d=int(x[1])
n=int(raw_input())
i=0
ctr=0
while i<n:
    z=raw_input().split(' ')
    x=int(z[0])
    y=int(z[1])
    r2=int(z[2])
    cnt=0
    dis=(x**2 + y**2)**0.5
    if dis>=r-d+r2:
        if dis > r+r2:
            cnt=0
        elif dis<=abs(r-r2):
            cnt=1
        else:
            cnt=0
        if cnt==1:
            ctr=ctr+1
    i=i+1
print ctr
    
