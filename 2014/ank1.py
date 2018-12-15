t=input()
i=0
while i<t:
    n=input()
    sm=0
    while n!=0:
        sm=sm+n%10
        n=n/10
    print sm
    i=i+1
