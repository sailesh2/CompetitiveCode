import sys
n=input()
x=(sys.stdin.readline().split())
p=1
i=0
sm=0
while i<n:
    if (int(x[i])==0):
        p=0
        break
    j=0
    cnt=0
    ctr=0
    while j<len(x[i]):
        if x[i][j]!='0' and x[i][j]!='1':
            p=int(x[i])
            cnt=1
            break
        if x[i][j]=='1':
            ctr=ctr+1
        if ctr>1:
            p=int(x[i])
            cnt=1
            break
        j=j+1
    if cnt==0:
        sm=sm+len(x[i])-1
    i=i+1

print int(p*pow(10,sm))
