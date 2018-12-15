def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

x=raw_input().split(' ')
p=int(x[0])
k=int(x[1])

i=0
gcdVal=gcd(k*k-1,p)
ctr=(p-1)/(p/gcdVal) + 1
print (ctr**(p/2))%1000000007
