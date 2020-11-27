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
b.reverse()
print(a)
print(b)


c=[]
i=0
while i<n:
    c.append((i+1)*(n-i))
    i=i+1

c.sort()
c.reverse()
print(c)
s=0
mod=998244353

i=0
ts=0
while i<n:
    s=(s+( ( (c[i]*a[i])%mod )*b[i])%mod)%mod
    i=i+1

print(s)

