inp=input().split(' ')
n=int(inp[0])
q=int(inp[1])
x=input()

arr=[]
ones=[]
ctrO=0
i=0
while i<n:
    arr.append(int(x[i]))
    if arr[i]==1:
        ctrO=ctrO+1
    ones.append(ctrO)
    i=i+1

mod=1000000007

pow2=[0]*(n+1)

p=1
i=0
while i<=n:
    pow2[i]=p
    p=(p*2)%mod
    i=i+1

i=0
while i<q:
    y=input().split(' ')
    l=int(y[0])-1
    r=int(y[1])-1
    total=r-l+1
    if l-1>=0:
        totalOnes=ones[r]-ones[l-1]
    else:
        totalOnes=ones[r]
    totalZeros=total-totalOnes
    ans=(pow2[totalZeros] * ((pow2[totalOnes]-1)%mod) )%mod
    print(ans)
    i=i+1
    
