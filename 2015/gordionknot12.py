n=input()
cnt=0
save=0
ctr=1
while 1:
    if save+1==n:
        break
    if save+ctr<n:
        save1=save+ctr
        ctr=ctr*2
        cnt=cnt+1
    else:
        save=save1
        ctr=1
print cnt   
