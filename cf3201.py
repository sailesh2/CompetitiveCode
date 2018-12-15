n=input()
ctr=0
while n>0:
    a=n%2
    if a==1:
        ctr=ctr+1
    n=n/2
print ctr
