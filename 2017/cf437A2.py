n=int(raw_input())
x=str(raw_input())
ctr1=0
ctr2=0
if x[0]=='F':
    cnt=1
else:
    cnt=0
i=1
while i<n:
    if x[i]=='F':
        if cnt==0:
            ctr1=ctr1+1
        cnt=1
    else:
        if cnt==1:
            ctr2=ctr2+1
        cnt=0
    i=i+1
if ctr1>ctr2:
    print "YES"
else:
    print "NO"
