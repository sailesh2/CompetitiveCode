import math
n=int(raw_input())
x=raw_input().split(' ')
arr=[]
brr=[]
sq=[]
i=0
ctr=0
z=0
while i<n:
   a=int(x[i])
   b=int(math.floor(a**0.5))
   c=b+1
   arr.append(min(abs(b*b-a),abs(c*c-a)))
   if arr[i]==0:
       ctr=ctr+1
       sq.append(a)
   else:
       brr.append(arr[i])
   i=i+1
if ctr>=n/2:
    i=0
    s=0
    sq.sort()
    sq.reverse()
    while i<ctr-(n/2):
        if sq[i]==0:
            s=s+2
        else:
            s=s+1
        i=i+1
    print s
else:
    brr.sort()
    i=0
    s=0
    while i<(n/2-ctr):
        s=s+brr[i]
        i=i+1
    print s
