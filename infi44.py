import math
n=input()
arr=[]
a=int(math.floor(math.log10(n)))
dig=a
print dig
while dig!=0:
    arr.append(dig%2)
    dig=dig/2
i=0
p2=1
prod=2
while i<len(arr):
    if arr[i]==1:
        p2=p2*prod
    prod=prod*prod
    i=i+1
s=0
p11=1
print p2
while n!=0:
    s=s+(n%10)*(p11%(10**9+7))*(p2%(10**9+7))
    p2=p2/2
    p11=(p11*11)
    n=n/10
print s%(10**9+7)
