import math

mod = 1000000007

def power2(n):
    if n<0:
        return pow(2,n)
    else:
        return pow(2,n,mod)
    
def mfib2(n,m):
	k=n-m-1
	ans=( ( power2(m-1) + power2(m-k) )%mod - 1 + mod )%mod
	ans=( power2(k-1) * ans )%mod
	v=( power2(m-k+1) * ( power2(k) -1 + mod )%mod )%mod
	v=( v - (k-1) + mod )%mod
	v=( power2(k-2) * v )%mod
	ans=(ans+v)%mod
	return int(math.ceil(ans))

x=input().split(' ')
n=int(x[0])
m=int(x[1])
print(mfib2(n,m))
