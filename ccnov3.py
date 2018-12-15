import math
arr=[0]*61
arr[0]=1
p=2
i=1
while i<61:
    arr[i]=p
    p=p*2
    i=i+1
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    s=int(math.log(k,2))
    var=float(n)/arr[s+1]
    var=var+(k-arr[s])*var*2
    print "%.9f" %var
    i=i+1
