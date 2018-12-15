arr=[0,1]
i=2
p=1
l=1
while i<=1000000:
    if (p*i)%107==p:
        break
    p=(p*i)%107
    l=l*i
    arr.append(l)
    i=i+1
lent=i
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    j=0
    while j<k:
        if n>=lent:
            n=arr[lent-1]
            break
        n=arr[n]
        j=j+1
    print n%107
    i=i+1
