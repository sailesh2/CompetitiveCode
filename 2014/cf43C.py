n=input()
x=raw_input().split(' ')
i=0
a=0
b=0
c=0
while i<n:
    if int(x[i])%3==0:
        a=a+1
    elif int(x[i])%3==1:
        b=b+1
    else:
        c=c+1
    i=i+1
if b<=c:
    print b+a/2
else:
    print c+a/2
