x=raw_input().split(' ')
n=int(x[0])
p=int(x[1])
q=int(x[2])
r=int(x[3])

y=raw_input().split(' ')
i=0
arr=[]
while i<n:
    arr.append(int(y[i]))
    i=i+1

i=n-1
maxi=-(10**19)
maxi2=-(10**19)
hasMax=[0]*n
hasMax2=[0]*n
while i>=0:
    maxi=max(maxi,r*arr[i])
    hasMax[i]=maxi
    maxi2=max(maxi2,q*arr[i]+hasMax[i])
    hasMax2[i]=maxi2
    i=i-1

i=0
maxiAns=-(10**19)
while i<n:
    maxiAns=max(maxiAns,p*arr[i]+hasMax2[i])
    i=i+1

print maxiAns

    
