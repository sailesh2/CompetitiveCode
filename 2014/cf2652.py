n=input()
x=raw_input().split(' ')
cnt=0
sm=0
i=0
while i<n:
    if cnt==0:
        if x[i]=='1':
            save=i
            cnt=1
    else:
        if x[i]=='0':
            sm=sm+i-save+1
            cnt=0
    i=i+1
if cnt==1:
    sm=sm+n-save+1
if sm==0:
    sm=1
print sm-1
            
        
