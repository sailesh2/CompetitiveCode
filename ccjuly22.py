t=input()
i=0
while i<t:
    n=raw_input().split(' ')
    x=abs(int(n[0]))
    y=abs(int(n[1]))
    if (x%2==0 and y%2==0) or (x%2!=0 and y%2!=0):
        if x>y:
            print 2*x
        else:
            print 2*y
    else:
        if x>y:
            print 2*x+1
        else:
            print 2*y-1
    i=i+1
