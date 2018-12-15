t=input()
i=0
while i<t:
    z=raw_input().split(' ')
    x=int(z[0])
    y=int(z[1])
    x1=int(z[2])
    y1=int(z[3])
    x2=int(z[4])
    y2=int(z[5])
    difx=0
    dify=0
    if abs(x-x1)<=abs(x-x2):
        difx=abs(x-x1)
    else:
        difx=abs(x-x2)
    if abs(y-y1)<=abs(y-y2):
        dify=abs(y-y1)
    else:
        dify=abs(y-y2)
    if difx<=dify:
        print difx
    else:
        print dify
    i=i+1
