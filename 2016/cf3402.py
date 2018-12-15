n=input()

x=raw_input().split(' ')
p=1
ctr=1
cnt=0
i= n-1
while i>=0:
    if int(x[i])==1:
        cnt=1
        break
    i=i-1
if cnt==0:
    print cnt
else:
    while i>=0:
        if int(x[i])==1:
            p=p*ctr
            ctr=1
        else:
            ctr=ctr+1
        i=i-1
    print p
