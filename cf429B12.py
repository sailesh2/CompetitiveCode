n=int(raw_input())

x=raw_input().split(' ')

sm=0
cnt=0
i=0
while i<n:
    a=int(x[i])
    sm=sm+a
    if(a%2!=0):
        cnt=1
        
    i=i+1

if sm%2!=0:
    print "First"
else:
    if cnt==1:
        print "First"
    else:
        print "Second"
        
