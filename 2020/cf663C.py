n=int(input())

mod = 10**9+7

p = pow(2,n-1,mod)

i=0
s=1
while i<n:
    s=(s*(i+1))%mod
    i=i+1

ans = (s-p)%mod
print(ans)
