n=input()
ar=[0]*1000001
i=0
while i<n:
    k=input()
    x=raw_input().split(' ')
    j=0
    while j<k:
        ar[int(x[j])]=1
        j=j+1
    i=i+1
i=1
while i<=1000001:
    if ar[i]==1:
        print i,
    i=i+1
