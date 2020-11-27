n=int(input())
x=input().split(' ')
y=input().split(' ')
a=[]
i=0
while i<n:
    a.append(int(x[i]))
    i=i+1

b=[]
i=0
while i<n:
    b.append(int(y[i]))
    i=i+1

a.sort()
b.sort()

c=[]
i=0
while i<n:
    c.append((i+1)*(n-i))
    i=i+1

s=0
mod=998244353

i=0
ts=0
while i<n:
    ts=(ts+(a[i]*b[i])%mod)%mod
    s=(s+ts)%mod
    i=i+1

##print(s)
i=0
ts=s
while i<n-1:
    ts=(ts-((a[i]*b[i])%mod*(n-i))%mod)%mod
  ##  print(ts)
    s=(s+ts)%mod
    i=i+1

print(s)

