z=raw_input().split(' ')
x=int(z[0])
y=int(z[1])
f=[x-y,x,y]
n=input()
print (pow(-1,n/3)*f[n%3])%1000000007
