def cnt1(n):
    ctr=0
    while n>0:
        if n%2==1:
            ctr=ctr+1
        n=n/2
    return ctr

t=input()
arr=[0]*t
i=0
while i<t:
    n=input()
    arr[i]=cnt1(n)
    i=i+1
x=0
cnt=0
i=0
while i<t:
    x=x^arr[i]
    i=i+1
i=0
while i<t:
    if x^arr[i]<arr[i]:
        cnt=1
        break
    i=i+1
if cnt==1:
    print "Shaka :)"
else:
    print "The other player :("
