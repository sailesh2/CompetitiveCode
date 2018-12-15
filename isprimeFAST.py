import random
t=input()
iter=10
while t>0:
    t-=1
    flag=0
    n=input()
    if n<2:
        print "NO"
        continue
    if n==2:
        print "YES"
        continue
    if n%2==0:
        print "NO"
        continue
    if n%3==0:
        print "NO"
        continue
    for i in range(0,iter):
        a=random.randint(1,n-1)
        x=pow(a,n-1,n)
        if x!=1:
            flag=1
    if flag==0:
        print "YES"
    else:
        print "NO"
    

