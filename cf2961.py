x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
sm=0
if a>=b:
    while b!=0:
        sm=sm+a/b
        temp=a
        a=b
        b=temp%b
else:
    while a!=0:
        sm=sm+b/a
        temp=b
        b=a
        a=temp%a
print sm
    
