x=input().split(' ')
n=int(x[0])
m=int(x[1])
mod=1000000007
v=pow((pow(2,m,mod)-1)%mod,n,mod)
print(v)
